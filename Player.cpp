#include <string>
#include <iostream>
#include<iomanip>
#include "Player.h"
#include "Statistic.h"


Player::Player() {
	playerName = "";
	jerseyNum = 0;
	numGames = 0;
}

void Player::Set_playerName(std::string name){
	playerName = name;
}
void Player::Set_jerseyNum(int num) {
	jerseyNum = num;
}


std::string Player::Get_playerName() {
	return playerName;
}
int Player::Get_jerseyNum() {
	return jerseyNum;
}
int Player::Get_numGames() {
	return numGames;
}

Statistic Player::Get_num3points(int index) {
	return num3points[index];
}
Statistic Player::Get_num2points(int index) {
	return num2points[index];
}
Statistic Player::Get_numFreeThrows(int index) {
	return numFreeThrows[index];
}


void Player::TotalGamePoints_calc() {


	for (int i = 0; i < numGames; i++) {
		TotalGamePoints[i] = num3points[i].Get_numPoints() + num2points[i].Get_numPoints() + numFreeThrows[i].Get_numPoints();
	}
}

void Player::ThreePtCalc() {
	int num_made = 0;
	int num_att = 0;

	for (int i = 0; i < numGames; i++) {
		num_made += num3points[i].Get_numPoints();
		num_att += num3points[i].Get_numAttempt();
	}

	Total3Stat.Set_numPoints(num_made);
	Total3Stat.Set_numAttempts(num_att);
}
void Player::TwoPtCalc() {
	int num_made = 0;
	int num_att = 0;

	for (int i = 0; i < numGames; i++) {
		num_made += num2points[i].Get_numPoints();
		num_att += num2points[i].Get_numAttempt();
	}

	Total2Stat.Set_numPoints(num_made);
	Total2Stat.Set_numAttempts(num_att);
}
void Player::FTCalc() {
	int num_made = 0;
	int num_att = 0;

	for (int i = 0; i < numGames; i++) {
		num_made += numFreeThrows[i].Get_numPoints();
		num_att += numFreeThrows[i].Get_numAttempt();
	}

	TotalFTStat.Set_numPoints(num_made);
	TotalFTStat.Set_numAttempts(num_att);
}
void Player::OverallPtCalc() {
	int num_made = 0;

	for (int i = 0; i < numGames; i++) {
		num_made += TotalGamePoints[i];
	}
	TotalOverallPoints = num_made;
}

void Player::addGame(Statistic threept, Statistic twopt, Statistic freept) {

	if (numGames == 15) {
		std::cout << " Max number of games exceeded. " << std::endl;
	}
	else {
		//std::cout << numGames << std::endl;
		num3points[numGames] = threept;
		num2points[numGames] = twopt;
		numFreeThrows[numGames] = freept;
		numGames++;

		TotalGamePoints_calc();
		ThreePtCalc();
		TwoPtCalc();
		FTCalc();
		OverallPtCalc();

	}
}

void Player::print() {
		
	std::cout << playerName << " " << "[" << jerseyNum << "]" << std::endl;

	std::cout << "Game" << " " << "3-Point FGs " << " " << "2-Point FGs " << " " << "Free Throws " << "Total" << std::endl;
	std::cout << "----" << " " << "------------" << " " << "------------" << " " << "------------" << "-----" << std::endl;

	for (int i = 0; i < numGames; i++) {
		
		std::cout << std::setw(4) << std::left << i + 1 << " " << std::setw(2) << num3points[i].Get_numPoints() << std::setw(2) << num3points[i].Get_numAttempt() << " (" << std::setw(3) << std::setprecision(0) << num3points[i].getPercent() << ")" << " "
			<< std::setw(2) << num2points[i].Get_numPoints() << std::setw(2) << num2points[i].Get_numAttempt() << " (" << std::setw(3) << std::setprecision(0) << num2points[i].getPercent() << ")" << " "
			<< std::setw(2) << numFreeThrows[i].Get_numPoints() << std::setw(2) << numFreeThrows[i].Get_numAttempt() << " (" << std::setw(3) << std::setprecision(0) << numFreeThrows[i].getPercent() << ")" << " "
			<< std::setw(5) << TotalGamePoints[i] << std::endl;
	}


	std::cout << std::setw(4) << std::left << "ALL" << " " << std::setw(2) << Total3Stat.Get_numPoints() << std::setw(2) << Total3Stat.Get_numAttempt() << " (" << std::setw(3) << std::setprecision(0) << Total3Stat.getPercent() << ")" << " "
		<< std::setw(2) << Total2Stat.Get_numPoints() << std::setw(2) << Total2Stat.Get_numAttempt() << " (" << std::setw(3) << std::setprecision(0) << Total2Stat.getPercent() << ")" << " "
		<< std::setw(2) << TotalFTStat.Get_numPoints() << std::setw(2) << TotalFTStat.Get_numAttempt() << " (" << std::setw(3) << std::setprecision(0) << TotalFTStat.getPercent() << ")" << " "
		<< std::setw(5) << TotalOverallPoints << std::endl;
}