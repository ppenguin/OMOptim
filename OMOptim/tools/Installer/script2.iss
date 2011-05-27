; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{2C27A169-E374-4967-BBE3-B488F2F412AA}
AppName=OMOptim
AppVerName=OMOptim 0.9
AppPublisher=Hubert Thieriot (ARMINES)
DefaultDirName={pf}\OMOptim
DefaultGroupName=OMOptim
OutputBaseFilename=setupOMOptim
Compression=lzma
SolidCompression=yes
;WizardImageFile=D:\Documents\MinEIT\Developpement\OMOptim\trunk\files\Resources\icons\Synchronize\Synchronize_256x256.png
;WizardSmallImageFile=D:\Documents\MinEIT\Developpement\OMOptim\trunk\files\Resources\icons\Synchronize\Synchronize_32x32.png

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "..\..\bin\OMOptim.exe"; DestDir: "{app}"; Flags: ignoreversion
Source:  "OMOptim.ico"; DestDir: "{app}";
Source:  "..\..\bin\QtCore4.dll"; DestDir: "{app}";
Source:  "..\..\bin\QtGui4.dll"; DestDir: "{app}";
Source:  "..\..\bin\QtXml4.dll"; DestDir: "{app}";
Source:  "..\..\bin\omniDynamic414_rt.dll"; DestDir: "{app}";
Source:  "..\..\bin\omniORB414_rt.dll"; DestDir: "{app}";
Source:  "..\..\bin\omnithread34_rt.dll"; DestDir: "{app}";
Source:  "..\..\bin\glpk_4_44.dll"; DestDir: "{app}";
Source:  "..\..\bin\qwt5.dll"; DestDir: "{app}";
Source:  "..\..\bin\mingwm10.dll"; DestDir: "{app}";
Source:  "..\..\bin\libgcc_s_dw2-1.dll"; DestDir: "{app}";
Source:  "..\..\bin\libstdc++-6.dll"; DestDir: "{app}";
;Source: "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\msvcp90.dll";  DestDir: "{app}"; OnlyBelowVersion: 0,9; Flags: restartreplace uninsneveruninstall sharedfile
;Source: "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\msvcr90.dll";  DestDir: "{app}"; OnlyBelowVersion: 0,9; Flags: restartreplace uninsneveruninstall sharedfile
;Source: "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\Microsoft.VC90.CRT.manifest";  DestDir: "{app}"; Flags: restartreplace uninsneveruninstall sharedfile
;Source: "C:\Program Files\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\*";  DestDir: "{app}\Microsoft.VC90.CRT"; Flags: restartreplace uninsneveruninstall sharedfile


[Icons]
Name: "{group}\OMOptim"; Filename: "{app}\OMOptim.exe" ; IconFilename: {app}\OMOptim.ico;
Name: "{commondesktop}\OMOptim"; Filename: "{app}\OMOptim.exe"; IconFilename: {app}\OMOptim.ico; IconIndex: 0; Tasks: desktopicon


[Registry]
; Cr�ation de la cl� primaire
Root: HKCU; Subkey: Software\OMOptim; Flags: uninsdeletekey
; Inscription des valeurs de cl�s secondaires
Root: HKCU; Subkey: Software\OMOptim\Setup; ValueType: string; ValueName: "Version"; ValueData: "0.1"

; add mineit path in environment variables
Root: HKCU; Subkey: Environment; ValueType: string; ValueName: "OMOptimPATH"; ValueData:  {app}

; etc.

[Dirs]
Name: {app}\Modelica
Name: {app}\Microsoft.VC90.CRT

[Code]
var

  LightMsgPage: TOutputMsgWizardPage;
  KeyPage: TInputQueryWizardPage;
  DataDirPage: TInputDirWizardPage;
  

  procedure URLLabelOnClick(Sender: TObject);
var
  ErrorCode: Integer;
begin
  ShellExec('open', 'http://www.ida.liu.se/labs/pelab/modelica/OpenModelica/releases/', '', '', SW_SHOWNORMAL, ewNoWait, ErrorCode);
end;

  procedure URLLabel2OnClick(Sender: TObject);
var
  ErrorCode: Integer;
begin
  ShellExec('open', 'http://www.microsoft.com/downloads/thankyou.aspx?familyId=9b2da534-3e03-4391-8a4d-074b9f2bc1bf&displayLang=fr', '', '', SW_SHOWNORMAL, ewNoWait, ErrorCode);
end;

procedure InitializeWizard;
var
  URLLabel: TNewStaticText;
    URLLabel2: TNewStaticText;
begin
  { Create the pages }



  LightMsgPage := CreateOutputMsgPage(wpWelcome,
    'Installations pr�alables', 'V�rifiez que les programmes suivants sont install�s sur votre ordinateur',

    'Open Modelica ' #13#13 #13#13 + 'Visual Studio run-time libraries');
    
    
    
    
     URLLabel := TNewStaticText.Create(LightMsgPage);
  URLLabel.Caption := 'Download open modelica';
  URLLabel.Cursor := crHand;
  URLLabel.OnClick := @URLLabelOnClick;
  URLLabel.Parent := LightMsgPage.Surface;
  { Alter Font *after* setting Parent so the correct defaults are inherited first }
  URLLabel.Font.Style := URLLabel.Font.Style + [fsUnderline];
  URLLabel.Font.Color := clBlue;
  URLLabel.Top := 20;


  URLLabel2 := TNewStaticText.Create(LightMsgPage);
  URLLabel2.Caption := 'Download VCRedist';
  URLLabel2.Cursor := crHand;
  URLLabel2.OnClick := @URLLabel2OnClick;
  URLLabel2.Parent := LightMsgPage.Surface;
  { Alter Font *after* setting Parent so the correct defaults are inherited first }
  URLLabel2.Font.Style := URLLabel2.Font.Style + [fsUnderline];
  URLLabel2.Font.Color := clBlue;
  URLLabel2.Top := 75;
    
    





  { Set default values, using settings that were stored last time if possible }



{ DataDirPage.Values[0] := GetPreviousData('DataDir', '');}
end;




