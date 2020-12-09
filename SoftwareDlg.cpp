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
	//ON_WM_ACTIVATE()
	//ON_WM_ERASEBKGND()
	//ON_WM_CTLCOLOR()
	ON_WM_CREATE()
	ON_WM_NCACTIVATE()
	ON_WM_NCPAINT()

	//ON_WM_DWMCOLORIZATIONCOLORCHANGED()
	//ON_WM_NCHITTEST()
	
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CSoftwareDlg message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CSoftwareDlg::OnInitDialog()
{
	m_colorDarkGray = RGB(60, 60, 60);
	m_brushDarkGray.CreateSolidBrush(m_colorDarkGray);
	m_colorDarkerGray = RGB(51, 51, 51);
	m_brushDarkerGray.CreateSolidBrush(m_colorDarkerGray);
	m_colorMostlyBlack = RGB(30, 30, 30);
	m_brushMostlyBlack.CreateSolidBrush(m_colorMostlyBlack);
	m_colorPowerShellBlue = RGB(0, 122, 204);
	m_brushPowerShellBlue.CreateSolidBrush(m_colorPowerShellBlue);



	m_colorOrange = RGB(255, 171 , 23);
	m_brushOrange.CreateSolidBrush(m_colorOrange);
	m_colorLightGray = RGB(220, 220, 220);;
	m_brushLightGray.CreateSolidBrush(m_colorLightGray);
	m_colorGray = RGB(100, 100, 100);
	m_brushGray.CreateSolidBrush(m_colorGray);
	m_colorBlack = RGB(0,0,0);
	m_brushBlack.CreateSolidBrush(m_colorBlack);
	m_colorRed = RGB(255,0,0);
	m_brushRed.CreateSolidBrush(m_colorRed);
	m_colorLightBlue = RGB(136, 217, 242);
	m_brushLightBlue.CreateSolidBrush(m_colorLightBlue);

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
		m_richEditCtrl.SetBackgroundColor(FALSE, m_colorMostlyBlack);

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
		//m_richEditCtrl.SetBackgroundColor(FALSE, m_colorMostlyBlack);
		//OnNcPaint(); this doesn't seem to do anything
	}
}


void CSoftwareDlg::OnNcPaint() {
	Default();
	//CDialogEx::OnNcPaint();
	//Sleep(1000);

	CDC* pDC = GetWindowDC();
	CRect rect;
	GetWindowRect(&rect);

	DrawTheCaption(&m_brushDarkGray);

	//Draw the left border
	GetWindowRect(&rect);
	rect.top = CaptionBarHeight;
	rect.left = 0;
	rect.bottom = rect.Size().cy;
	rect.right = GetSystemMetrics(SM_CXDLGFRAME) + GetSystemMetrics(SM_CXPADDEDBORDER) + GetSystemMetrics(SM_CXEDGE);
	pDC->FillRect(rect, &m_brushDarkerGray);

	//Draw the right border
	GetWindowRect(&rect);
	rect.top = CaptionBarHeight;
	rect.right = rect.Size().cx;
	rect.left = rect.right - GetSystemMetrics(SM_CXDLGFRAME) - GetSystemMetrics(SM_CXPADDEDBORDER) - GetSystemMetrics(SM_CXEDGE) - 1;
	rect.bottom = rect.Size().cy;
	pDC->FillRect(rect, &m_brushDarkerGray);

	//Draw the bottom border
	GetWindowRect(&rect);
	printRectDimensions(rect, "Bare Rect");
	rect.bottom = rect.Size().cy;
	rect.top = rect.bottom -GetSystemMetrics(SM_CYDLGFRAME) - GetSystemMetrics(SM_CXPADDEDBORDER) - GetSystemMetrics(SM_CYEDGE);
	rect.left = 0;
	rect.right = rect.Size().cx;
	pDC->FillRect(rect, &m_brushOrange);
	printRectDimensions(rect, "Bottom Orange Border");


	ReleaseDC(pDC);
}

BOOL CSoftwareDlg::OnNcActivate(BOOL wParam) {
	//The 2 following functions do *basically* the same thing... and when this function is overwritten, for some reason they use a different window style(...an OLD style)
	//CDialogEx::OnNcActivate(wParam);
	//Default();

	//this does fuck all
	//HWND hWnd = GetSafeHwnd();
	//char className[256];
	//GetClassName(hWnd, className, 256);
	//WNDCLASSEX windowInfo;
	//HINSTANCE hInstance = AfxGetInstanceHandle();
	//BOOL stuff = GetClassInfoEx(hInstance, className, &windowInfo);
	//windowInfo.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 

	//draw "active" title bar
	if (wParam) {
		DrawTheCaption(&m_brushDarkGray);
	}
	//draw the caption using the inactive colors
	else {
		DrawTheCaption(&m_brushDarkerGray);
	}
	
	return wParam;
}

//NOT AN OVERRIDE OF THE WINDOWS FUNCTIONALITY
//Drawing the caption appears to be necessary in 3 places - OnNcPaint() and twice(once for the active color and once for the inactive color) in OnNcActivate()
void CSoftwareDlg::DrawTheCaption(CBrush* captionColor) {
	CDC* pDC = GetWindowDC();
	CRect rect;
	GetWindowRect(&rect);
	
	//Draw top "caption" box
	rect.top = 0;
	rect.left = 0;
	rect.bottom = rect.top + CaptionBarHeight;
	rect.right = rect.Size().cx; //- 3*(GetSystemMetrics(SM_CXSMSIZE)) +GetSystemMetrics(SM_CXFRAME) + GetSystemMetrics(SM_CXPADDEDBORDER)
	pDC->FillRect(rect, captionColor);
	printRectDimensions(rect, "Dialog Frame + Border");
	
	//...& draw the icon icon
	HINSTANCE hInstance = AfxGetInstanceHandle();
	HICON smallIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	HDC hdc = pDC->GetSafeHdc();
	DrawIconEx(*pDC, 5, 6, smallIcon, 16, 16, 0, 0, DI_NORMAL);


	//CDialogEx::DrawCaption(pDC, rect, DC_ICON | DC_TEXT | DC_SMALLCAP | DC_BUTTONS);
	rect.left = rect.Size().cx - 3 * (GetSystemMetrics(SM_CXSMSIZE));
	rect.right = rect.Size().cx;
	//CDialogEx::DrawCaption(pDC, rect, DC_BUTTONS); //This sadly doesn't work.
	//NEED TO ADD TEXT
	//NEED TO MAKE THE TEXT FADE OUT

	ReleaseDC(pDC);
}

//void CSoftwareDlg::OnNcPaint() {
//
//	//Maybe this forces it to wait?
//	LRESULT stuff = Default();
//	//Default();
//	//CDialogEx::OnNcPaint();
//	Sleep(1000);
//	//CPaintDC DC(this);
//	CDC* pDC = GetWindowDC();
//	CDC memdc;
//	memdc.CreateCompatibleDC(pDC);
//	//CBitmap* pBMPOld = memdc.SelectObject(m_bmpObject);
//
//
//
//	CRect rect;
//
//	//draw border
//	//pDC->GetClipBox(&rc);
//	GetWindowRect(&rect);
//	long fullWindowHeight = rect.Size().cy;
//	long fullWindowWidth = rect.Size().cx;
//
//	rect.top = 0;
//	rect.left = 0;
//	rect.bottom = fullWindowHeight;
//	rect.right = fullWindowWidth;
//	printRectDimensions(rect, "Full Window");
//	pDC->FillRect(rect, &m_brushRed); //this just doesn't work at all for some reason??
//	//pDC->FillSolidRect(rect, m_colorRed); //and this doens't do anything either
//	
//	//draw padding
//
//
//	//draw frame
//	GetWindowRect(&rect);
//	rect.top = GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYBORDER);
//	rect.right = rect.Width() - (2 * rect.top);
//	rect.left = GetSystemMetrics(SM_CXDLGFRAME) + GetSystemMetrics(SM_CXBORDER);
//	rect.bottom = rect.top + GetSystemMetrics(SM_CYCAPTION);
//	
//	
//	//pDC->FillRect(rect, &m_brushRed);
//
//	//need to try these out
//	//pDC->FillSolidRect();
//	//pDC->FloodFill();
//	//pDC->SetDCBrushColor(m_color);
//	//rect.right = rect.left + GetSystemMetrics(SM_CXMENUSIZE);
//	//rect.bottom = rect.top + GetSystemMetrics(SM_CYMENUSIZE);
//	//int stuff = GetSystemMetrics(SM_CXPADDEDBORDER);
//	
//	//
//	
//	//rect.bottom = rect.top + GetSystemMetrics(SM_CXPADDEDBORDER);
//	
//
//	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
//
//	//memdc.SelectObject(pBMPOld);
//
//
//
//	//CDialogEx::OnNcPaint();
//	//CPaintDC other_dc(this);
//	//GetWindowRect(&clientRect);
//	//clientRect.top = clientRect.bottom + GetSystemMetrics(SM_CYCAPTION);
//	//m_brush.CreateSolidBrush(RGB(136, 217, 242));
//	//other_dc.FillRect(clientRect, &m_brush);
//
//
//	ReleaseDC(pDC);
//}

void CSoftwareDlg::printRectDimensions(CRect rect, std::string windowName) {
	OutputDebugStringA(windowName.c_str());
	std::string rectDimensions = "\n\tTop:\t" + std::to_string(rect.top) + "\n";
	rectDimensions += "\tLeft:\t" + std::to_string(rect.left) + "\n";
	rectDimensions += "\tBottom\t:" + std::to_string(rect.bottom) + "\n";
	rectDimensions += "\tRight\t:" + std::to_string(rect.right) + "\n";
	rectDimensions += "Size:\n\tHeight:\t" + std::to_string(rect.Size().cy) + "\n\tWidth:\t" + std::to_string(rect.Size().cx) + "\n";
	OutputDebugStringA(rectDimensions.c_str());
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


//void CSoftwareDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
//{
//
//	HWND hWnd = GetSafeHwnd();
//	BOOL fCallDWP;
//	// Extend the frame into the client area.
//	MARGINS margins;
//
//	margins.cxLeftWidth = LEFTEXTENDWIDTH;      // 8
//	margins.cxRightWidth = RIGHTEXTENDWIDTH;    // 8
//	margins.cyBottomHeight = BOTTOMEXTENDWIDTH; // 20
//	margins.cyTopHeight = TOPEXTENDWIDTH;       // 27
//
//	hr = DwmExtendFrameIntoClientArea(hWnd, &margins);
//
//	if (!SUCCEEDED(hr))
//	{
//		// Handle the error.
//	}
//
//	fCallDWP = true;
//	lRet = 0;

	//fCallDWP = !DwmDefWindowProc(hWnd, message, wParam, lParam, &lRet);
	
	//////////////////////////////////////////
	// How to get a WNDCLASSEX object
	///////////////////////////////////////
	//HWND hWnd = GetSafeHwnd();
	//char className[256];
	//GetClassName(hWnd, className, 256);
	//WNDCLASSEX windowInfo;
	//HINSTANCE hInstance = AfxGetInstanceHandle();
	//BOOL stuff = GetClassInfoEx(hInstance, className, &windowInfo);

	//windowInfo.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//CDialogEx::OnActivate(nState, pWndOther, bMinimized);

//}

//
//BOOL CSoftwareDlg::OnEraseBkgnd(CDC* pDC)
//{
//	CRect rc;
//	pDC->GetClipBox(&rc);
//	pDC->FillSolidRect(rc, m_color);
//	pDC->SetTextColor(RGB(255, 0, 0));
//	return TRUE;
//
//}

							
HBRUSH CSoftwareDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	CRect rc;
	pDC->GetClipBox(&rc);
	pDC->FillSolidRect(rc, m_colorRed);

	pDC->SetTextColor(RGB(255, 0, 0));
	return m_brushLightGray;

}

//
//HBRUSH CSoftwareDlg::CtlColor(CDC* pDC, UINT nCtlColor)
//{
//	pDC->SetTextColor(RGB(255, 0, 0));
//
//	return m_brush;
//}

void CSoftwareDlg::OnColorizationColorChanged(DWORD dwColorizationColor, BOOL bOpacity)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	// TODO: Add your message handler code here and/or call default
	dwColorizationColor = 0xAA0000FF;

	CDialogEx::OnColorizationColorChanged(dwColorizationColor, bOpacity);
}





LRESULT CSoftwareDlg::OnNcHitTest(CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	HWND hWnd = GetSafeHwnd();
	WORD highWord = point.y;
	WORD lowWord = point.x;
	DWORD lParam = MAKELPARAM(lowWord, highWord);
	LRESULT lResult = DefWindowProc(WM_NCHITTEST, NULL, lParam);
	
	if (lResult == HTCLOSE) {
		//do nothing
	}
	else {
		Default();
	}

	//lResult = DwmDefWindowProc(hWnd, WM_NCHITTEST, NULL, lParam, &lResult);

	if (lResult == HTCLOSE) {
		//do nothing
	}
	else {
		Default();
	}

	return CDialogEx::OnNcHitTest(point);
}


int CSoftwareDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	//if (CDialogEx::OnCreate(lpCreateStruct) == -1) //I don't know whether to keep this or not...
	//	return -1;

	//The following three lines somehow account for the rounded corners you get if you try to override the NC area yourself(by handling the WM_ON_NCPAINT message)
	#pragma comment( lib, "UxTheme")
	HWND hwnd = GetSafeHwnd();
	SetWindowTheme(hwnd, L"", L"");

	return 0;
}
