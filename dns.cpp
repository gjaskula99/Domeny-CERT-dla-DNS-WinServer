#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream input, output, outputD;
	input.open("domains.txt", ios::in);
	if(input.good() && input.is_open())
	{
		output.open("output.bat", ios::out);
		outputD.open("outputDelete.bat", ios::out);
		if(output.good() && output.is_open() && outputD.good() && outputD.is_open())
		{
			//dnscmd . /zoneadd test.com /primary
			//dnscmd . /RecordAdd {domain} {hostname} {record type} {IP address}
			//dnscmd . /zoneDelete test.com /F
			//195.187.6.33
			//195.187.6.34
			//195.187.6.35
			string domain = "", commandZone = "", commandRecord = "", commandRecordWWW = "", commandDel = "";
			while(!input.eof())
			{
				input >> domain;
				commandZone = 	"dnscmd . /zoneadd " + domain + " /primary";
				commandRecord = "dnscmd . /RecordAdd " + domain + " . A 195.187.6.33";
				commandRecordWWW = "dnscmd . /RecordAdd " + domain + " www A 195.187.6.33";
				commandDel = "dnscmd . /zoneDelete " + domain + " /F";
				output << commandZone << "\n" << commandRecord << "\n" << commandRecordWWW << "\n";
				outputD << commandDel << "\n";
			}
			output.close();
		}
		input.close();
	}
	else return -1;
	return 0;
}
