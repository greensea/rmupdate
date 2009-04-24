/***************************************************************
 * Name:      RMupdateManagerApp.h
 * Purpose:   Defines Application Class
 * Author:    gs (gs@bbxy.net)
 * Created:   2009-04-23
 * Copyright: gs (http://www.gsea.com.cn/)
 * License:
 **************************************************************/

#ifndef RMUPDATEMANAGERAPP_H
#define RMUPDATEMANAGERAPP_H

#include <wx/app.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>

struct mapping_dirs_t{
    wxArrayString SrcPath;
    wxArrayString DesPath;
};

struct mapping_files_t{
    wxArrayString SrcPath;
    wxArrayString DesPath;
};

struct fileinfo_t{
    wxArrayString path;
    wxArrayString md5;
};

struct proj_info_t{
    wxString name;
    mapping_dirs_t MappingDirs;
    mapping_files_t MappingFiles;
    long AbsVer;
    long SubAbsVer;
    long UpdateTime;
};

class RMupdateManagerApp : public wxApp
{
    public:

        virtual bool OnInit();

        proj_info_t GetProjInfo();
        bool SaveProjInfo(proj_info_t proj);
        bool OpenProj();
        bool CreateProj();
        bool LoadProjConfig(const char* path);

    private:
        proj_info_t ProjInfo;

        bool CreateProjConfig(const char* path);


};

#endif // RMUPDATEMANAGERAPP_H