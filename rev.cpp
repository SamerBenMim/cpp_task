#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    ifstream inFile("revenue_ext_v2.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    map<string, double> storeRevenue;
    map<string, double>::iterator it; 
    double totalRevenue = 0.0;

    string store;
    double revenue;
    while (inFile >> store >> revenue) {
        if (storeRevenue.find(store) == storeRevenue.end()) {
            storeRevenue[store] = 0.0; // Initialize revenue for new store
        }
        storeRevenue[store] += revenue;
        totalRevenue += revenue;
    }

    inFile.close();

    cout << "Accumulative Quarterly Sales for Each Store:" << endl;
    cout << "------------------------------------------" << endl;

  	for ( it = storeRevenue.begin(); it != storeRevenue.end(); ++it) {
        cout << left << setw(12) << it->first << " : " << it->second << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << "Total Revenue: " << totalRevenue << endl;

    // Find store with the largest sales revenue
    string largestStore;
    double largestRevenue = 0.0;
 	it = storeRevenue.begin();
	largestStore = it->first;
	largestRevenue = it->second;

	for (; it != storeRevenue.end(); ++it) {
    	if (it->second > largestRevenue) {
        	largestRevenue = it->second;
        	largestStore = it->first;
    	}
	}	

    cout << "Store with the Largest Sales Revenue: " << largestStore << ": " << largestRevenue << endl;

    return 0;
}

