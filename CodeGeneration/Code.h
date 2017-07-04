#pragma once
#include <vector>
#include <string>

class Code {
public:
	///Constructor -> look main generator
	Code() { CodeGenerator(); };

	///Main algorithm/generator that is called
	void CodeGenerator();

	//Getters
	///Get the current amount of layers generated
	int GetCurrentLayers();

	//Setters
	///Set maximum allowed lines
	void SetMaxLines(int);
	///Increase or deacrease tab spaces formatting
	void SetSpaces(int);
	///Warning: CLEARS ALL WORDS!
	void ClearProWords();
	///Add a word to proWord
	void AddProWord(std::string);
	///Increase or decrease layers
	void SetLayer(int);

	//End and start functions
	void PrintAll();
	void PrintStart();
	void StartLayer();
	void EndLayer();
	void PrintSpace();
	bool HasClass();

	//Random events
	int RandomRange(int, int);
	std::string SizeOfRandom();
	std::string RandomFunction();
	void RandomFullFunction();
	void RandomFullLoop();
	std::string RandomProWord();
	std::string RandomType();
	std::string RandomValue();
	std::string RandomAccesor();
	void RandomStart();
	bool LoopChance();
	void LayerStuff();
	void ClassStuff();
	std::string GetSetRandomClassName();
	void PrintRandomClassVars();
	bool FiftyFifty();


	//Public words and formatting
	///Spaces for layers
	std::vector<std::string> Space[10];
	///Words that come up, pro stands for programming
	std::vector<std::string> ProWord = {
		"Dispatcher", "Terminal", "Velocity", "Particle_Numbers",
		"Truncate", "UltSize", "Height", "Weight", "Wage","Gap",
		"Diameter", "AreaOfEffect", "IQ", "SleepingTime", 
		"Sex", "Gender", "ApacheHelicopter", "Cost", "TotalCost",
		"Country","Origin", "Damage", "Defense", "Budget",
		"Trojan", "Beerus", "Walrus", "HasProtection"
	};
	std::vector<std::string> RClassName = {
		"Circle", "Dispatcher", "Object", "Particle",
		"Watermelon", "Triangle", "Rectangle", "Trump", "Employee",
		"Actor", "Program", "Database", "Book", "Movie"
	};
	std::vector<std::string> RType = {
		"enum", "bool", "int", "long int", "unsigned int",
		"long long", "long unsigned int", "float", "double",
		"unsigned double", "unsigned float", "long float",
		"long double", "std::string", "std::vector<int>",
		"std::vector<double>", "std::vector<std::string>",
		"std::vector<float>", "int"
	};
	std::vector<std::string> RFunction = {
		"GetWidth", "GetLenght", "GetNumber", "GetTicket",
		"GetClass", "GetRekt", "Get_OS", "GetHeight", 
		"GetVisibility", "GetWage", "GetArea", "SetArea",
		"SetWage", "SetVisibility", "SetTracer", "GetTracer",
		"ResizeTo", "ChangeSizeTo", "CheckForError"
	};
	std::vector<std::string> RValue = {
		"0", "1", "5", "1337", "69", "88", "88", "8888",
		"88-69+88", "-69", "-88", "-1337", "NULL", "NULL",
		"is-infinite", "\"\"", "Dispatcher", "Terminal", "Velocity", "Particle_Numbers",
		"Truncate", "UltSize", "Height", "Weight", "Wage","Gap",
		"Diameter", "AreaOfEffect", "IQ", "SleepingTime",
		"Sex", "Gender", "ApacheHelicopter", "Cost", "TotalCost",
		"Country","Origin", "Damage", "Defense", "Budget",
		"Trojan", "Beerus", "Walrus", "HasProtection"
	};
	std::vector<std::string> RAcc = { "protected\:", "private\:","public\:" };

	


private:
	int MaxLines = 50;
	int CurrentLayers = 0;
	int Layer = 0;
	int MaxLayers = 10;
	int MaxClassVars = 12;
	int ContentFill = 2;


	std::string CurrentClass = "";
	
	std::string LayerEnd = "}";
	std::string LayerStart = "{";
};