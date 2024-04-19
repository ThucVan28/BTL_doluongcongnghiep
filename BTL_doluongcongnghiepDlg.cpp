
// BTL_doluongcongnghiepDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BTL_doluongcongnghiep.h"
#include "BTL_doluongcongnghiepDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBTLdoluongcongnghiepDlg dialog



CBTLdoluongcongnghiepDlg::CBTLdoluongcongnghiepDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BTL_DOLUONGCONGNGHIEP_DIALOG, pParent)
	, m_rad_samp5s(0)
	, m_rad_samp10s(0)
	, m_rad_samp30s(0)
	, m_rad_samp1m(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CBTLdoluongcongnghiepDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_sethigh1, m_spin_sethigh1);
	DDX_Control(pDX, IDC_EDT_sethigh1, m_edt_sethigh1);
	DDX_Control(pDX, IDC_EDT_setlow1, m_edt_setlow1);
	DDX_Control(pDX, IDC_SPIN_setlow1, m_spin_setlow1);
	DDX_Control(pDX, IDC_EDT_temp1, m_edt_temp1);
	DDX_Control(pDX, IDC_EDT_temp2, m_edt_temp2);
	DDX_Control(pDX, IDC_EDT_sethigh2, m_edt_sethigh2);
	DDX_Control(pDX, IDC_EDT_setlow2, m_edt_setlow2);
	DDX_Control(pDX, IDC_SPIN_sethigh2, m_spin_sethigh2);
	DDX_Control(pDX, IDC_SPIN_setlow2, m_spin_setlow2);
	DDX_Control(pDX, IDC_COMBO_name, m_combo_name);
	DDX_Control(pDX, IDC_BTN_connect, m_btn_connect);
	DDX_Control(pDX, IDC_BTN_start, m_btn_start);
	DDX_Check(pDX, IDC_RAD_samp5s, m_rad_samp5s);
	DDX_Check(pDX, IDC_RAD_samp10s, m_rad_samp10s);
	DDX_Check(pDX, IDC_RAD_samp30s, m_rad_samp30s);
	DDX_Check(pDX, IDC_RAD_sanmp1m, m_rad_samp1m);
	DDX_Control(pDX, IDC_STATIC_coloral1, m_static_alarmh1);
	DDX_Control(pDX, IDC_CHECK_alarm1, m_check_alarm1);
	DDX_Control(pDX, IDC_STATIC_coloral2, m_static_alarml1);
	DDX_Control(pDX, IDC_STATIC_coloral3, m_static_alarmh2);
	DDX_Control(pDX, IDC_STATIC_coloral4, m_static_alarml2);
	DDX_Control(pDX, IDC_CHECK_alarm2, m_check_alarm2);
}

BEGIN_MESSAGE_MAP(CBTLdoluongcongnghiepDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sethigh1, &CBTLdoluongcongnghiepDlg::OnDeltaposSpinsethigh1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_setlow1, &CBTLdoluongcongnghiepDlg::OnDeltaposSpinsetlow1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sethigh2, &CBTLdoluongcongnghiepDlg::OnDeltaposSpinsethigh2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_setlow2, &CBTLdoluongcongnghiepDlg::OnDeltaposSpinsetlow2)
	ON_BN_CLICKED(IDC_BTN_connect, &CBTLdoluongcongnghiepDlg::OnBnClickedBtnconnect)
	ON_BN_CLICKED(IDC_BTN_start, &CBTLdoluongcongnghiepDlg::OnBnClickedBtnstart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RAD_samp5s, &CBTLdoluongcongnghiepDlg::OnBnClickedRadsamp5s)
	ON_BN_CLICKED(IDC_RAD_samp10s, &CBTLdoluongcongnghiepDlg::OnBnClickedRadsamp10s)
	ON_BN_CLICKED(IDC_RAD_samp30s, &CBTLdoluongcongnghiepDlg::OnBnClickedRadsamp30s)
	ON_BN_CLICKED(IDC_RAD_sanmp1m, &CBTLdoluongcongnghiepDlg::OnBnClickedRadsanmp1m)
	ON_WM_CTLCOLOR()
	//ON_STN_CLICKED(IDC_STATIC_alarm3, &CBTLdoluongcongnghiepDlg::OnStnClickedStaticalarm3)
	ON_BN_CLICKED(IDC_BTN_calib_zero, &CBTLdoluongcongnghiepDlg::OnBnClickedBtncalibzero)
	ON_BN_CLICKED(IDC_BTN_calib_gain, &CBTLdoluongcongnghiepDlg::OnBnClickedBtncalibgain)
END_MESSAGE_MAP()


// CBTLdoluongcongnghiepDlg message handlers

BOOL CBTLdoluongcongnghiepDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//find port -----------------------------------------------------------------------------
	TCHAR lpTargetPath[5000]; // buffer to store the path of the COMPORTS
	DWORD test;

	int gotPort = 0; // in case the port is not found
	for (int i = 0; i < 255; i++) // checking ports from COM0 to COM255
	{
		CString str;
		str.Format(_T("%d"), i);
		CString ComName = CString("COM") + CString(str); // converting to COM0, COM1, COM2

		test = QueryDosDevice(ComName, (LPTSTR)lpTargetPath, 5000);

		// Test the return value and error if any
		if (test != 0) //QueryDosDevice returns zero if it didn't find an object
		{
			m_combo_name.AddString(ComName); // add to the ComboBox
			gotPort++; // found port
		}
		if (::GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
			lpTargetPath[1000]; // in case the buffer got filled, increase size of the buffer.
			continue;
		}
	}
	if (gotPort == 0)// if not port
		m_combo_name.AddString(_T("No Active Ports Found")); // to display error message incase no ports found
	//-------------------------------------------------------------------------------


	m_rad_samp5s = 1;
	samp_t = 5000;

	//setup gia tri canh bao nhiet do high1
	m_spin_sethigh1.SetRange(-100, 100); // range alarm temperature
	m_spin_sethigh1.SetBase(20);
	
	
	UINT val1;
	val1 = m_spin_sethigh1.GetBase(); // lấy giá trị hiện tại của spin control
	CString str;   
	str.Format(_T("%d"), (int)val1); 
	m_edt_sethigh1.SetWindowText(str); 
	
	//setup gia tri canh bao nhiet do low1
	m_spin_setlow1.SetRange(-100, 100);
	m_spin_setlow1.SetBase(20);
	val1 = m_spin_setlow1.GetBase();
	str.Format(_T("%d"), (int)val1);
	m_edt_setlow1.SetWindowText(str);

	//setup gia tri canh bao nhiet do high2
	m_spin_sethigh2.SetRange(-100, 100);
	m_spin_sethigh2.SetBase(20);
	val1 = m_spin_sethigh2.GetBase();
	str.Format(_T("%d"), val1);
	m_edt_sethigh2.SetWindowText(str);

	//setup gia tri canh bao nhiet do low2
	m_spin_setlow2.SetRange(-100, 100);
	m_spin_setlow2.SetBase(20);
	val1 = m_spin_setlow2.GetBase();
	str.Format(_T("%d"), val1);
	m_edt_setlow2.SetWindowText(str);
	

	//setup font 
	CFont font;
	CFont temp;
	font.CreateFont(
		13,                        // nHeight
		13,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial"));                 // lpszFacename

	GetDlgItem(IDC_STATIC_temp1)->SetFont(&font);
	GetDlgItem(IDC_STATIC_temp2)->SetFont(&font);
	GetDlgItem(IDC_STATIC_alarm1)->SetFont(&font);
	GetDlgItem(IDC_STATIC_alarm2)->SetFont(&font);
	GetDlgItem(IDC_STATIC_alarm3)->SetFont(&font);
	GetDlgItem(IDC_STATIC_alarm4)->SetFont(&font);
	
	temp.CreateFont(
		40,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial"));
	GetDlgItem(IDC_EDT_temp1)->SetFont(&temp);
	GetDlgItem(IDC_EDT_temp2)->SetFont(&temp);

		// color alarm
	brush_alarmh1.CreateSolidBrush(RGB(0, 255, 0));
	brush_alarml1.CreateSolidBrush(RGB(0, 255, 0));

	brush_alarmh2.CreateSolidBrush(RGB(0, 255, 0));
	brush_alarml2.CreateSolidBrush(RGB(0, 255, 0));

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBTLdoluongcongnghiepDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBTLdoluongcongnghiepDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBTLdoluongcongnghiepDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//___________________________________________________
//**SPIN ALRAM_______________________________________

void CBTLdoluongcongnghiepDlg::OnDeltaposSpinsethigh1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	UINT temp; 
	CString str;
	temp = m_spin_sethigh1.GetBase(); 
	if (pNMUpDown->iDelta > 0)
	{
		// Đã nhấp vào nút Lên
		cout_sethigh1++;
	}
	else
	{
		// Đã nhấp vào nút Xuống
		cout_sethigh1--; 
	}
	//*pResult = 0;
	val_sethigh1 = (int)temp + cout_sethigh1;
	str.Format(_T("%d"),val_sethigh1); 
	m_edt_sethigh1.SetWindowText(str); 
	UpdateData(FALSE);
}


void CBTLdoluongcongnghiepDlg::OnDeltaposSpinsetlow1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	UINT temp; 
	CString str;
	temp = m_spin_setlow1.GetBase();
	if (pNMUpDown->iDelta > 0)
	{
		// Đã nhấp vào nút Lên
		cout_setlow1++;
	}
	else
	{
		// Đã nhấp vào nút Xuống
		cout_setlow1--;
	}
	//*pResult = 0;
	val_setlow1 = (int)temp + cout_setlow1;
	str.Format(_T("%d"), val_setlow1);
	m_edt_setlow1.SetWindowText(str);
	UpdateData(FALSE);
	
}


void CBTLdoluongcongnghiepDlg::OnDeltaposSpinsethigh2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	UINT temp;
	CString str;
	temp = m_spin_sethigh2.GetBase();
	if (pNMUpDown->iDelta > 0)
	{
		// Đã nhấp vào nút Lên
		cout_sethigh2++;
	}
	else
	{
		// Đã nhấp vào nút Xuống
		cout_sethigh2--;
	}
	val_sethigh2 = (int)temp + cout_sethigh2;
	str.Format(_T("%d"), val_sethigh2);
	m_edt_sethigh2.SetWindowText(str);
	UpdateData(FALSE); 
	*pResult = 0;
}


void CBTLdoluongcongnghiepDlg::OnDeltaposSpinsetlow2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	
	UINT temp;
	CString str;
	temp = m_spin_setlow2.GetBase();
	if (pNMUpDown->iDelta > 0)
	{
		// Đã nhấp vào nút Lên
		cout_setlow2++;
	}
	else
	{
		// Đã nhấp vào nút Xuống
		cout_setlow2--;
	}
	val_setlow2 = (int)temp + cout_setlow2;
	str.Format(_T("%d"), val_setlow2);
	m_edt_setlow2.SetWindowText(str);
	UpdateData(FALSE);
	*pResult = 0;
}

//___________________________________________

void CBTLdoluongcongnghiepDlg::OnBnClickedBtnconnect()
{
	UpdateData(TRUE);
	// lay nameport tu combobox
	int idx = m_combo_name.GetCurSel();
	CString str;
	m_combo_name.GetLBText(idx, str);
	CString port_i;
	port_i = _T("\\\\.\\") + str;

	hPort = CreateFile(port_i, // Pointer to the name of the port
		GENERIC_READ | GENERIC_WRITE,
		// Access (read-write) mode
		0,            // Share mode
		NULL,         // Pointer to the security attribute
		OPEN_EXISTING,// How to open the serial port
		0,            // Port attributes
		NULL);        // Handle to port with attribute

	if (hPort == (HANDLE)ERROR_FILE_NOT_FOUND)
	{
		MessageBox(_T("Serial port connecting error"), _T("Error"), MB_OK);
	}
	else
	{
		MessageBox(_T("Serial port connected "), _T("Sucess"), MB_OK);
	}

	//SETUP DCB++++++++++++++++++++++++++++++++++

	DCB PortDCB;

	// Initialize the DCBlength member. 
	PortDCB.DCBlength = sizeof(DCB);

	// Get the default port setting information.
	GetCommState(hPort, &PortDCB);

	// Change the DCB structure settings.
	PortDCB.BaudRate = 9600;              // Current baud 
	PortDCB.fBinary = TRUE;               // Binary mode; no EOF check 
	PortDCB.fParity = TRUE;               // Enable parity checking 
	PortDCB.fOutxCtsFlow = FALSE;         // No CTS output flow control 
	PortDCB.fOutxDsrFlow = FALSE;         // No DSR output flow control 
	PortDCB.fDtrControl = DTR_CONTROL_ENABLE;
	// DTR flow control type 
	PortDCB.fDsrSensitivity = FALSE;      // DSR sensitivity 
	PortDCB.fTXContinueOnXoff = TRUE;     // XOFF continues Tx 
	PortDCB.fOutX = FALSE;                // No XON/XOFF out flow control 
	PortDCB.fInX = FALSE;                 // No XON/XOFF in flow control 
	PortDCB.fErrorChar = FALSE;           // Disable error replacement 
	PortDCB.fNull = FALSE;                // Disable null stripping 
	PortDCB.fRtsControl = RTS_CONTROL_ENABLE;
	// RTS flow control 
	PortDCB.fAbortOnError = FALSE;        // Do not abort reads/writes on 
	// error
	PortDCB.ByteSize = 8;                 // Number of bits/byte, 4-8 
	PortDCB.Parity = NOPARITY;            // 0-4=no,odd,even,mark,space 
	PortDCB.StopBits = ONESTOPBIT;        // 0,1,2 = 1, 1.5, 2 

	// Configure the port according to the specifications of the DCB 
	// structure.
	if (!SetCommState(hPort, &PortDCB))
	{
		// Could not configure the serial port.
		//dwError = GetLastError();
		MessageBox(TEXT("Unable to configure the serial port"),
			TEXT("Error"), MB_OK);
		//return FALSE;
	}
	else
	{
		MessageBox(TEXT("Configure the serial port sucessed"),
			TEXT("Sucess"), MB_OK);
	}

	// Retrieve the timeout parameters for all read and write operations on the port. 
	COMMTIMEOUTS CommTimeouts;
	GetCommTimeouts(hPort, &CommTimeouts);

	// Change the COMMTIMEOUTS structure settings.
	CommTimeouts.ReadIntervalTimeout = MAXDWORD;
	CommTimeouts.ReadTotalTimeoutMultiplier = 10;
	CommTimeouts.ReadTotalTimeoutConstant = 10;
	CommTimeouts.WriteTotalTimeoutMultiplier = 0;
	CommTimeouts.WriteTotalTimeoutConstant = 0;

	// Set the timeout parameters for all read and write operations
	// on the port. 
	if (!SetCommTimeouts(hPort, &CommTimeouts))
	{
		// Could not set the timeout parameters.
		MessageBox(TEXT("Unable to set the timeout parameters"),
			TEXT("Error"), MB_OK);
		
	}
	else
	{
		MessageBox(TEXT("Set the timeout parameters sucessed"),
			TEXT("Sucess"), MB_OK);
	}

}

void CBTLdoluongcongnghiepDlg::WriteData(char* chr_send)
{
	int nSize = 1;
	DWORD* p;
	DWORD idx = (DWORD)nSize;
	p = &idx;

	WriteFile(hPort,              // Port handle 
		chr_send,              // Pointer to the data to write   
		idx,                  // Number of bytes to write
		p, // Pointer to the number of bytes   
		// written
		NULL                // Must be NULL for Windows CE 
	);
	BYTE Byte;
	DWORD dwBytesTransferred, dwCommModemStatus;
	CString str1;
	str_receive = _T("");
	// Specify a set of events to be monitored for the port.
	SetCommMask(hPort, EV_RXCHAR);
	// Wait for an event to occur for the port.
	WaitCommEvent(hPort, &dwCommModemStatus, 0);


	if (dwCommModemStatus & EV_RXCHAR)
	{
		// Loop for waiting for the data.
		do
		{
			// Read the data from the serial port.
			ReadFile(hPort, &Byte, 1, &dwBytesTransferred, NULL);

			// Display the data read.

			if (dwBytesTransferred == 1)
			{
				str1.Format(_T("%c"), Byte);
				str_receive = str_receive + str1;
			}

		} while (dwBytesTransferred == 1);
	}
	

}



void CBTLdoluongcongnghiepDlg::OnBnClickedBtnstart()
{
	
	SetTimer(1, samp_t, NULL); //đặt timer lấy mẫu
	SetTimer(2, 500, NULL);		//Thời gian nhấp nháy cảnh báo
	WriteData("d");				// gửi tín hiệu yêu cầu stm32 gửi nhiệt độ
	CString str_tempo1;	
	CString str_tempo2;
	str_tempo1 = str_receive;

	WriteData("e");
	str_tempo2 = str_receive;

	value_temp1 = _tstof(str_tempo1);
	value_temp2 = _tstof(str_tempo2);

	str_tempo1 = str_tempo1 + _T("°C");
	str_tempo2 = str_tempo2 + _T("°C");

	m_edt_temp1.SetWindowText(str_tempo1);
	m_edt_temp2.SetWindowText(str_tempo2);
	UpdateData(FALSE);
}


void CBTLdoluongcongnghiepDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(TRUE);
	if (nIDEvent == 1) // đọc và hiển thị nhiệt độ theo sample time
	{
		//Sensor1
		WriteData("d");
		CString str_tempo1;
		CString str_tempo2;
		str_tempo1 = str_receive;
		value_temp1 = _tstof(str_tempo1);
		str_tempo1 = str_tempo1 + _T("°C");
		m_edt_temp1.SetWindowText(str_tempo1);

		//Sensor2
		WriteData("e");
		str_tempo2 = str_receive;
		value_temp2 = _tstof(str_tempo2);
		str_tempo2 = str_tempo2 + _T("°C");
		m_edt_temp2.SetWindowText(str_tempo2);
		
		SetTimer(1, samp_t, NULL);
	}
	if (nIDEvent == 2)// nhấp nháy Alarm
	{
		if (m_check_alarm1.GetCheck() == 1)
		{
			if (value_temp1 > val_sethigh1) // nhấp nháy alarm1 nếu nhiệt độ cao
			{
				if (cout_alarm1 % 2 == 0) 
				{
					brush_alarmh1.DeleteObject();
					brush_alarmh1.CreateSolidBrush(RGB(255, 0, 0));
					cout_alarm1++;
				}
				else
				{
					brush_alarmh1.DeleteObject();
					brush_alarmh1.CreateSolidBrush(RGB(255, 255, 255));
					cout_alarm1++;
				}
				
			}
			else // nếu thỏa thỏa tầm nhiệt độ 
			{
				brush_alarmh1.DeleteObject();
				brush_alarmh1.CreateSolidBrush(RGB(0, 255, 0)); // green
			}

			if (value_temp1 < val_setlow1)
			{
				if (cout_alarm1 % 2 == 0)
				{
					brush_alarml1.DeleteObject();
					brush_alarml1.CreateSolidBrush(RGB(255, 0, 0));
					cout_alarm1++;
				}
				else
				{
					brush_alarml1.DeleteObject();
					brush_alarml1.CreateSolidBrush(RGB(255, 255, 255));
					cout_alarm1++;
				}
			}
			else
			{
				brush_alarml1.DeleteObject();
				brush_alarml1.CreateSolidBrush(RGB(0, 255, 0));
			}
		}
		else
		{
			//alarm white color neu khong tich checkbox Enable Alarm
			brush_alarmh1.DeleteObject();
			brush_alarmh1.CreateSolidBrush(RGB(255, 255, 255));
			brush_alarml1.DeleteObject();
			brush_alarml1.CreateSolidBrush(RGB(255, 255, 255));
		}
		//update trang thai alarm
		if (m_check_alarm2.GetCheck() == 1) // kiem tra Enable Alarm2
		{
			if (value_temp2 > val_sethigh2) // nhấp nháy alarm1 nếu nhiệt độ cao
			{
				if (cout_alarm2 % 2 == 0)
				{
					brush_alarmh2.DeleteObject();
					brush_alarmh2.CreateSolidBrush(RGB(255, 0, 0));
					cout_alarm2++;
				}
				else
				{
					brush_alarmh2.DeleteObject();
					brush_alarmh2.CreateSolidBrush(RGB(255, 255, 255));
					cout_alarm2++;
				}

			}
			else // nếu thỏa thỏa tầm nhiệt độ -> alarm màu xanh
			{
				brush_alarmh2.DeleteObject();
				brush_alarmh2.CreateSolidBrush(RGB(0, 255, 0)); // green

			}

			if (value_temp2 < val_setlow2) //kiem tra dieu kien nhiet do muc thap
			{
				if (cout_alarm2 % 2 == 0)
				{
					brush_alarml2.DeleteObject();
					brush_alarml2.CreateSolidBrush(RGB(255, 0, 0));
					cout_alarm2++;
				}
				else
				{
					brush_alarml2.DeleteObject();
					brush_alarml2.CreateSolidBrush(RGB(255, 255, 255));
					cout_alarm2++;
				}
			}
			else
			{
				brush_alarml2.DeleteObject();
				brush_alarml2.CreateSolidBrush(RGB(0, 255, 0));
			}
		}
		else
		{
			//alarm white color neu khong tich checkbox Enable Alarm
			brush_alarmh2.DeleteObject();
			brush_alarmh2.CreateSolidBrush(RGB(255, 255, 255));
			brush_alarml2.DeleteObject();
			brush_alarml2.CreateSolidBrush(RGB(255, 255, 255));
		}
		// update color alarm
		m_static_alarmh1.Invalidate();
		m_static_alarmh1.UpdateWindow();
		m_static_alarml1.Invalidate();
		m_static_alarml1.UpdateWindow();

		m_static_alarmh2.Invalidate();
		m_static_alarmh2.UpdateWindow();
		m_static_alarml2.Invalidate();
		m_static_alarml2.UpdateWindow();

	}
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}



void CBTLdoluongcongnghiepDlg::OnBnClickedRadsamp5s()
{
	// TODO: Add your control notification handler code here
	samp_t = 5000;
}


void CBTLdoluongcongnghiepDlg::OnBnClickedRadsamp10s()
{
	// TODO: Add your control notification handler code here
	samp_t = 10000;
}


void CBTLdoluongcongnghiepDlg::OnBnClickedRadsamp30s()
{
	// TODO: Add your control notification handler code here
	samp_t = 30000;
}


void CBTLdoluongcongnghiepDlg::OnBnClickedRadsanmp1m()
{
	// TODO: Add your control notification handler code here
	samp_t = 60000;
}


// thay doi mau nen cho static text Alarm
HBRUSH CBTLdoluongcongnghiepDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (nCtlColor == CTLCOLOR_STATIC && pWnd->GetDlgCtrlID() == IDC_STATIC_coloral1)
		hbr = brush_alarmh1;
	if (nCtlColor == CTLCOLOR_STATIC && pWnd->GetDlgCtrlID() == IDC_STATIC_coloral2)
		hbr = brush_alarml1;
	if (nCtlColor == CTLCOLOR_STATIC && pWnd->GetDlgCtrlID() == IDC_STATIC_coloral3)
		hbr = brush_alarmh2;
	if (nCtlColor == CTLCOLOR_STATIC && pWnd->GetDlgCtrlID() == IDC_STATIC_coloral4)
		hbr = brush_alarml2;
	
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}



void CBTLdoluongcongnghiepDlg::OnBnClickedBtncalibzero()
{
	// TODO: Add your control notification handler code here
	
	WriteData("c");
	str_receive = _T("");
	WriteData("d");

	CString str_tempo1;
	
	str_tempo1 = str_receive;
	value_temp1 = _tstof(str_tempo1);
	str_tempo1 = str_tempo1 + _T("°C");
	m_edt_temp1.SetWindowText(str_tempo1);
	UpdateData(FALSE);
	//Sensor2
	CString str_tempo2;
	WriteData("e");
	str_tempo2 = str_receive;
	value_temp2 = _tstof(str_tempo2);
	str_tempo2 = str_tempo2 + _T("°C");
	m_edt_temp2.SetWindowText(str_tempo2);
	//UpdateData(FALSE);
	UpdateData(FALSE);
	
}


void CBTLdoluongcongnghiepDlg::OnBnClickedBtncalibgain()
{
	// TODO: Add your control notification handler code here
	WriteData("b");
	

}
