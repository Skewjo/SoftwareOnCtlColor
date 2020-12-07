#include "stdafx.h"
#include "AboutDlg.h"
#include "Software.h"
#include "SoftwareDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//Windows Dialog inherited function overrides
/////////////////////////////////////////////////////////////////////////////
// CSoftwareDlg dialog
/////////////////////////////////////////////////////////////////////////////
CSoftwareDlg::CSoftwareDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSoftwareDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoftwareDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_hIcon						= AfxGetApp()->LoadIcon(IDI_ICON1);
}
void CSoftwareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoftwareDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSoftwareDlg, CDialogEx)
	//{{AFX_MSG_MAP(CSoftwareDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_CTLCOLOR_REFLECT()
	//ON_WM_NCPAINT()
	//ON_WM_NCACTIVATE()
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CSoftwareDlg message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CSoftwareDlg::OnInitDialog()
{
	m_color = RGB(136, 217, 242);
	m_brush.CreateSolidBrush(m_color);

	CDialogEx::OnInitDialog();

	//CDialogEx::SetBackgroundColor(RGB(136, 217, 242), 1);
	
	

	CWnd* pMainDlg = GetDlgItem(IDD_SOFTWARE_DIALOG);

	if (pMainDlg)
	{
		pMainDlg->GetClientRect(&clientRect);
	}
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon

	CWnd* pPlaceholder = GetDlgItem(IDC_PLACEHOLDER);

	if (pPlaceholder)
	{
		CRect rect;
		pPlaceholder->GetClientRect(&rect);
		
		if (!m_richEditCtrl.Create(WS_VISIBLE | ES_READONLY | ES_MULTILINE | ES_AUTOHSCROLL | WS_HSCROLL | ES_AUTOVSCROLL | WS_VSCROLL, rect, this, 0))
			return FALSE;

		m_font.CreateFont(-11, 0, 0, 0, FW_REGULAR, 0, 0, 0, BALTIC_CHARSET, 0, 0, 0, 0, "Courier New");
		m_richEditCtrl.SetFont(&m_font);
		m_richEditCtrl.SetBackgroundColor(FALSE, m_color);

	}
	m_nTimerID = SetTimer(0x1234, 1000, NULL);	//Used by OnTimer function to refresh dialog box & OSD

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CSoftwareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
/////////////////////////////////////////////////////////////////////////////
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
/////////////////////////////////////////////////////////////////////////////
void CSoftwareDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CSoftwareDlg::OnNcPaint() {
	CDialogEx::OnNcPaint();
	CPaintDC other_dc(this);
	GetWindowRect(&clientRect);
	clientRect.top = clientRect.bottom + GetSystemMetrics(SM_CYCAPTION);
	m_brush.CreateSolidBrush(RGB(136, 217, 242));
	other_dc.FillRect(clientRect, &m_brush);
}

HCURSOR CSoftwareDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}
void CSoftwareDlg::OnTimer(UINT nIDEvent)
{
	CDialogEx::OnTimer(nIDEvent);
}
void CSoftwareDlg::OnDestroy()
{
	if (m_nTimerID)
		KillTimer(m_nTimerID);

	m_nTimerID = NULL;

	MSG msg;
	while (PeekMessage(&msg, m_hWnd, WM_TIMER, WM_TIMER, PM_REMOVE));

	CDialogEx::OnDestroy();
}


BOOL CSoftwareDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case ' ':
			Sleep(1000);
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}



BOOL CSoftwareDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rc;
	pDC->GetClipBox(&rc);
	pDC->FillSolidRect(rc, m_color);
	pDC->SetTextColor(RGB(255, 0, 0));
	return TRUE;

}

							
HBRUSH CSoftwareDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	pDC->SetTextColor(RGB(255, 0, 0));
	return m_brush;

}


HBRUSH CSoftwareDlg::CtlColor(CDC* pDC, UINT nCtlColor)
{
	pDC->SetTextColor(RGB(255, 0, 0));

	return m_brush;
}