#include <iostream>
#include <locale>
#include <string>
#include <clocale>
#include <aspose_ocr.h>
#include <Aspose.Cells.h>

string folder_path = "E:\\c++\\FIFA OCR\\data";


String PerformOcrOnImage() {
        
    std::string image_path = folder_path + "\\sample.png";
    const size_t len = 4096;
    wchar_t buffer[len] = { 0 };
    size_t size = aspose::ocr::page(image_path.c_str(), buffer, len);
    std::wcout << buffer;
    return buffer;
}


void PrintToExcel(String textResult)
{
    String folderPath = folder_path.c_str();
    StringPtr outDir = new String(folderPath);
    StringPtr outputManageWorksheets = outDir->StringAppend(new String("result.xlsx"));
    intrusive_ptr<IWorkbook>  workbook = Factory::CreateIWorkbook();
    int i = workbook->GetIWorksheets()->Add();
    intrusive_ptr<IWorksheet> worksheet = workbook->GetIWorksheets()->GetObjectByIndex(i);
    intrusive_ptr<ICells> cells = worksheet->GetICells();
    intrusive_ptr<ICell> cell = cells->GetObjectByIndex(new String("A1"));
    Console::Write(new String("HAHA"));
    Console::WriteLine(cell->GetStringValue());
    worksheet->SetName(new String("My Worksheet"));
    workbook->Save(outputManageWorksheets);
}

int main()
{
    String textResult = PerformOcrOnImage();
    PrintToExcel(textResult);
    
    return 0;
}