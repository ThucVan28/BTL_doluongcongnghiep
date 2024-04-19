
// BTL_doluongcongnghiepDlg.h : header file
//

#pragma once


// CBTLdoluongcongnghiepDlg dialog
class CBTLdoluongcongnghiepDlg : public CDialogEx
{
// Construction
public:
	CBTLdoluongcongnghiepDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BTL_DOLUONGCONGNGHIEP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	HANDLE hPort;

	//int tam = 0;
	int cout_sethigh1 =0;
	int cout_setlow1 = 0;
	int val_sethigh1;
	int val_setlow1;
	int cout_sethigh2 = 0;
	int cout_setlow2 = 0;
	int val_sethigh2;
	int val_setlow2;

	int m_rad_samp5s;
	int m_rad_samp10s;
	int m_rad_samp30s;
	int m_rad_samp1m;

	float value_temp1;
	float value_temp2;

	int cout_alarm1 = 0;
	int cout_alarm2 = 0;

	unsigned int samp_t; // th?i gian l?y m?u
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_spin_sethigh1;
	CEdit m_edt_sethigh1;
	afx_msg void OnDeltaposSpinsethigh1(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit m_edt_setlow1;
	CSpinButtonCtrl m_spin_setlow1;
	afx_msg void OnDeltaposSpinsetlow1(NMHDR* pNMHDR, LRESULT* pResult);
	
	CEdit m_edt_temp1;
	CEdit m_edt_temp2;
	CEdit m_edt_sethigh2;
	CEdit m_edt_setlow2;

	CSpinButtonCtrl m_spin_sethigh2;
	CSpinButtonCtrl m_spin_setlow2;
	afx_msg void OnDeltaposSpinsethigh2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinsetlow2(NMHDR* pNMHDR, LRESULT* pResult);

	CComboBox m_combo_name;
	CButton m_btn_connect;
	afx_msg void OnBnClickedBtnconnect();
	CButton m_btn_start;
	afx_msg void OnBnClickedBtnstart();
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	void CBTLdoluongcongnghiepDlg::WriteData(char* chr_send);
	CString str_receive;

	afx_msg void OnBnClickedRadsamp5s();
	afx_msg void OnBnClickedRadsamp10s();
	afx_msg void OnBnClickedRadsamp30s();
	afx_msg void OnBnClickedRadsanmp1m();

	CBrush brush_alarmh1; //doi tuong thay doi mau Alarm
	CBrush brush_alarml1;
	CBrush brush_alarmh2;
	CBrush brush_alarml2;
	CBrush brush_backgr1;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CStatic m_static_alarmh1;
	CStatic m_static_alarml1;

	CStatic m_static_alarmh2;
	CStatic m_static_alarml2;

	CButton m_check_alarm2;
	CButton m_check_alarm1;
	afx_msg void OnBnClickedBtncalibzero();
	afx_msg void OnBnClickedBtncalibgain();
};
