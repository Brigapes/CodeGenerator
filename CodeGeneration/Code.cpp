#include <iostream>
#include "Code.h"
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>

void Code::RandomFullFunction() {
	PrintSpace(); Sleep(sleep_time);
	std::cout << RandomFunction() << "();" << std::endl;
}

void Code::RandomFullLoop() {
	PrintSpace(); Sleep(sleep_time);
	if (FiftyFifty()) {
		std::cout << "    while(" << RandomProWord() << ") {" << std::endl;
		PrintSpace(); Sleep(sleep_time); std::cout << "         ";
		std::cout << RandomFunction() << "(" << RandomProWord() << ");" << std::endl;
		PrintSpace(); Sleep(sleep_time); std::cout << "         ";
		std::cout << RandomProWord() << "++;" << std::endl;
		PrintSpace(); Sleep(sleep_time);
		std::cout << "}" << std::endl;
	}
	else {
		std::cout << "     for("<<RandomType()<<" i = " << RandomValue() << "; i<" << RandomProWord() << "; i++) {"<<std::endl;
		PrintSpace(); Sleep(20); std::cout << "         ";
		std::cout << RandomFunction() << "(" << RandomProWord() << ");" << std::endl;
		PrintSpace(); Sleep(sleep_time); std::cout << "         ";
		std::cout << RandomProWord() << "++;" << std::endl;
		PrintSpace(); Sleep(sleep_time); 
		std::cout << "}" << std::endl;
	}

}

bool Code::FiftyFifty() {
	Sleep(sleep_time); //srand(time(NULL));
	float r = rand() % 10;
	if (r < 5) { return true; }
	else { return false; }
}

std::string Code::RandomAccesor() {
	return RAcc[RandomRange(0, RAcc.size())];
}

void Code::PrintRandomClassVars() {
	std::cout << RandomAccesor() << std::endl;

	PrintSpace(); Sleep(sleep_time);
	for (int i = 0; i < (RandomRange(0, MaxClassVars)); i++) {	Sleep(sleep_time); 
	std::cout << RandomType() << " " << RandomProWord() << " = " << RandomValue() << std::endl;
		PrintSpace();}
	std::cout << "" << std::endl; PrintSpace();
	std::cout << RandomAccesor() << std::endl;
	PrintSpace(); Sleep(sleep_time);
	for (int i = 0; i < (RandomRange(0, MaxClassVars+4)); i++) {Sleep(sleep_time); 
	std::cout << RandomType() << " " << RandomFunction() << "( " << RandomType() << " );" << std::endl;
		PrintSpace();}
	
}

std::string Code::RandomType() {Sleep(sleep_time);
	return RType[RandomRange(0,RType.size())];
}
std::string Code::RandomValue() {
	Sleep(sleep_time);
	return RValue[RandomRange(0, RValue.size())];
}


bool Code::LoopChance(){
	if (Layer <= 1 && CurrentLayers > 2) { return false; }
	Sleep(sleep_time);	//srand(time(NULL));
	if (CurrentLayers >= MaxLines) { return false; }
	float crr = MaxLayers / 10 * Layer;
	int a = RandomRange(1, 100);
	//std::cout << " crr: " << crr << " r: " << a ;
	if (Layer > MaxLayers) { return false; }
	if (crr<rand()%MaxLayers) { return true; }
	else { return false; }
}

void Code::RandomStart() {
	//if (Layer == 0) { ClassStuff(); return; }
	if (LoopChance()) {
		StartLayer();}
	else { EndLayer();}}

void Code::PrintSpace() {
	std::string space;
	for (int i = 0; i < Layer; i++) {
		space += "    ";}
	std::cout << space;}

void Code::EndLayer() {
	std::cout << "" << std::endl;
	PrintSpace();
	std::cout << LayerEnd << std::endl;
	Layer = Layer - 1;
	if (LoopChance()==true) {
		RandomStart(); } }
bool Code::HasClass() { if (CurrentClass == "") { return false; } }

std::string Code::GetSetRandomClassName() {Sleep(sleep_time);
	std::string crr= RClassName[RandomRange(0, RClassName.size())];
	CurrentClass = crr; return crr;}

void Code::ClassStuff() {Sleep(sleep_time);
	StartLayer();
	PrintSpace();

	std::cout << " class " << GetSetRandomClassName() << std::endl; Sleep(sleep_time);
	PrintSpace(); Sleep(sleep_time);
	PrintRandomClassVars();
	EndLayer();
}

void Code::LayerStuff() {
	Sleep(sleep_time);
	for (int i = 0; i < ContentFill; ++i) {
		Sleep(sleep_time);
		if (FiftyFifty()) {
			RandomFullFunction();
		}
		else { break; }
		for (int i = 0; i < ContentFill; ++i) {
			Sleep(sleep_time);
			if (FiftyFifty()) {
				RandomFullLoop();
			}
			else { break; }
		}
	}
}


void Code::StartLayer() {
	if (Layer == 0) {
		Layer++; CurrentLayers++;
		PrintSpace();
		std::cout << LayerStart << std::endl;
		ClassStuff();
		return;
	}
		if (!LoopChance()) { return; } 
	CurrentLayers++;
	PrintSpace();
	std::cout << LayerStart << std::endl;
	Sleep(sleep_time);
	
	LayerStuff(); //Code stuff start
	SetLayer(Layer+1);
	RandomStart();
}

int Code::RandomRange(int min, int max) {
	//srand(time(NULL));
	    return rand() % (int)(min+max);
}
std::string Code::SizeOfRandom() {
	//return Code::RandomRange(ProWord.size());
	return NULL;
}
std::string Code::RandomFunction() {Sleep(sleep_time);
	return RFunction[RandomRange(0,RFunction.size())];
}
std::string Code::RandomProWord() {
	return ProWord[RandomRange(0, ProWord.size())];
}

int Code::GetCurrentLayers()
{
	return CurrentLayers;
}

void Code::SetMaxLines(int input)
{
	MaxLines = input;
}

void Code::SetSpaces(int)
{
}

void Code::SetLayer(int input){
	if (input > 0) {
		CurrentLayers+=input;
		Layer = input;		}
	else {
		Layer = input;
	}}

void Code::AddProWord(std::string input)
{ProWord.push_back(input);}
void Code::ClearProWords() { /*ProWord.clear;*/ }

void Code::PrintAll()
{
}
void Code::PrintStart() {
	srand(time(NULL));
	std::cout << "#include <iostream>" << std::endl; Sleep(sleep_time);
	std::cout << "#include <vector>" << std::endl; Sleep(sleep_time);
	std::cout << "#include <string>" << std::endl; Sleep(sleep_time);
	std::cout << "#include \"boost.h\"" << std::endl; Sleep(sleep_time);
	std::cout << "#include \"CustomFunctions.h\"" << std::endl; Sleep(sleep_time);
}


///Main guideline
void Code::CodeGenerator() {
	srand(time(NULL));
	Sleep(1000);
	PrintStart();
	SetLayer(0);

	RandomStart();

	//Close all remaining layers
	while (!(Layer <= 0)) {
		EndLayer();
	}EndLayer();




	


}
