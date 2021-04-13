#include "combGUI.h"

[System::STAThreadAttribute]

void main(array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	CombGUI::combGUI form;
	//form.Show();
	System::Windows::Forms::Application::Run(% form);

	std::string path = *form.pathPtr;
	std::string filename = *form.filenamePtr;
	double basefreq = form.basefreq;
	int32_t filtering_method = form.filtering_method;

	CombFilter::combFilter myFilter(path, filename, basefreq, filtering_method);

	myFilter.eventsCallback();

	
}