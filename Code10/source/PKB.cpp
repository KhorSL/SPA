#include<stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "PKB.h"
#include "TNode.h"

std::unordered_map<std::string, INTEGER> PKB::variableMap;

INTEGER variableMapNextIndex = 0;

int PKB::setProcToAST(PROC p, TNode* r) {
	return 0;
}

TNode* PKB::getRootAST (PROC p){
	return nullptr;
}

INDEX PKB::insertVariable(std::string variableName) {	
	variableMap.emplace(variableMap, variableMapNextIndex);
	variableMapNextIndex++;
	return variableMap.at(variableName);
}

std::string PKB::getVariableName(INDEX index) {
	if (index < 0) {
		throw std::invalid_argument("Received negative value.");
	}

	for (std::pair<std::string, INTEGER> element : variableMap) {
		if (element.second == index) {
			return element.first;
		}
	}

	throw "Index not found."
}

INDEX PKB::getVariableIndex(std::string variableName) {
	return variableMap.at(variableName);
}

INTEGER PKB::getSize() {
	return variableMap.size();
}

std::unordered_map<std::string, int> PKB::getVariables() {
	return variableMap;
}
