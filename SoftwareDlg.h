// SoftwareDlg.h : header file
//
// created by Unwinder
// modified by Skewjo
/////////////////////////////////////////////////////////////////////////////

#ifndef _SOFTWAREDLG_H_INCLUDED_
#define _SOFTWAREDLG_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxdialogex.h>
#include <string>
#include <time.h>
#include <vector>

#include "framework.h"

const int CaptionBarHeight = GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CXPADDEDBORDER) + GetSystemMetrics(SM_CYSMCAPTION) + 1; //GetSystemMetrics(SM_CYEDGE); //??

class CSoftwareDlg : public CDialogEx
{
// Construction
public:
	CSoftwareDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSoftwareDlg)
	enum { IDD = IDD_SOFTWARE_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoftwareDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL						PreTranslateMessage(MSG* pMsg);
	HICON						m_hIcon;
	UINT						m_nTimerID;
	CFont						m_font;
	CRichEditCtrl				m_richEditCtrl;
	CRect						clientRect;


	//Colors & Brushes
	COLORREF					m_colorDarkGray;
	CBrush						m_brushDarkGray;
	COLORREF					m_colorDarkerGray;
	CBrush						m_brushDarkerGray;
	COLORREF					m_colorMostlyBlack;
	CBrush						m_brushMostlyBlack;
	COLORREF					m_colorPowerShellBlue;
	CBrush						m_brushPowerShellBlue;


	COLORREF					m_colorOrange;
	CBrush						m_brushOrange;
	COLORREF					m_colorLightGray;
	CBrush						m_brushLightGray;
	COLORREF					m_colorGray;
	CBrush						m_brushGray;
	COLORREF					m_colorBlack;
	CBrush						m_brushBlack;
	COLORREF					m_colorRed;
	CBrush						m_brushRed;
	COLORREF					m_colorLightBlue;
	CBrush						m_brushLightBlue;
	
	void printRectDimensions(CRect, std::string);
	void DrawTheCaption(CBrush* captionColor);
	
	
	
	// Generated message map functions
	//{{AFX_MSG(CSoftwareDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg BOOL OnEraseBkgnd(CDC* pDC); //this function appears to take over??
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnNcPaint();
	afx_msg BOOL OnNcActivate(BOOL);
	afx_msg void OnColorizationColorChanged(DWORD dwColorizationColor, BOOL bOpacity);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
/////////////////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////////////////
