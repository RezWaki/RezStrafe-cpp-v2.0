#pragma once
#define BASIC
#include <stdio.h>
#include <fstream>
#include <Windows.h>
#include <WinBase.h>
#include "options.h"

namespace RezStrafecpp {

//	using namespace StrafeInfo;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Location = System::Drawing::Point(26, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(13, 66);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->Location = System::Drawing::Point(2, 25);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(62, 17);
			this->panel2->TabIndex = 1;
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &main::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 20;
			this->timer2->Tick += gcnew System::EventHandler(this, &main::timer2_Tick);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(64, 64);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"main";
			this->TopMost = true;
			this->TransparencyKey = System::Drawing::Color::White;
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &main::main_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void main_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyData == System::Windows::Forms::Keys::Insert){
					 timer1->Start();
					 timer2->Start();
				 }

				 if(e->KeyData == System::Windows::Forms::Keys::Delete){
					 timer1->Stop();
					 timer2->Stop();
				 }
			 }
	private: System::Void main_Load(System::Object^  sender, System::EventArgs^  e) {
				 options^ showopt = gcnew options();
				 showopt->Show();
				 
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 //LPPOINT curpos;
				 //GetCursorPos(curpos);
				 //options^ showopt = gcnew options();
				 int scrw = System::Convert::ToInt16(System::IO::File::ReadAllText("width.ini", System::Text::Encoding::Default));
				 int scrh = System::Convert::ToInt16(System::IO::File::ReadAllText("height.ini", System::Text::Encoding::Default));
				 int config1 = System::Convert::ToInt16(System::IO::File::ReadAllText("strafeangle.ini", System::Text::Encoding::Default));
				 System::Drawing::Point ptre;
				 System::Drawing::Point get = System::Windows::Forms::Cursor::Position; 
				 ptre.X = scrw/2-config1; //dividing for 2 - got strafeangle
				 ptre.Y = get.Y; //get y position
				 System::Windows::Forms::Cursor::Position::set(ptre);
			 }
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
				// options^ showopt = gcnew options();
				 System::Drawing::Point ptre;
				 //read all infos in integer
				 int scrw = System::Convert::ToInt16(System::IO::File::ReadAllText("width.ini", System::Text::Encoding::Default));
				 int scrh = System::Convert::ToInt16(System::IO::File::ReadAllText("height.ini", System::Text::Encoding::Default));
				 int config1 = System::Convert::ToInt16(System::IO::File::ReadAllText("strafeangle.ini", System::Text::Encoding::Default));
				// Sytem::Drawing::Point get;
				 System::Drawing::Point get = System::Windows::Forms::Cursor::Position; 
				 ptre.X = scrw/2+config1*2; //dividing for 2 + got strafeangle and multiplied by 2
				 ptre.Y = get.Y; //get y position
				 System::Windows::Forms::Cursor::Position::set(ptre); //make strafes
			 }
};
}
