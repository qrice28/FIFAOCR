#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <aspose_ocr.h>
#include <Aspose.Cells.h>

void PerformOcrOnImage() {
    
    std::string image_path = "E:\\c++\\FIFA OCR\\data\\sample.png";
    const size_t len = 4096;
    wchar_t buffer[len] = { 0 };
    size_t size = aspose::ocr::page(image_path.c_str(), buffer, len);
    std::wcout << buffer;
}

void AddingWorksheetsToNewExcelFile()
{
    StringPtr outDir = new String("E:\\c++\\FIFA OCR\\data\\");
    StringPtr outputManageWorksheets = outDir->StringAppend(new String("result.xlsx"));
    intrusive_ptr<IWorkbook>  workbook = Factory::CreateIWorkbook();
    int i = workbook->GetIWorksheets()->Add();
    intrusive_ptr<IWorksheet> worksheet = workbook->GetIWorksheets()->GetObjectByIndex(i);
    worksheet->SetName(new String("My Worksheet"));
    workbook->Save(outputManageWorksheets);
}

int main()
{
    PerformOcrOnImage();
    AddingWorksheetsToNewExcelFile();
    return 0;
}