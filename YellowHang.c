#pragma config(Sensor, port7,  TopButton,      sensorVexIQ_Touch)
#pragma config(Sensor, port8,  BottomButton,   sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          LeftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor2,          MantisLeft,    tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor4,          RightArmMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor10,         LeftArmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor11,         MantisRight,   tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor12,         RightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void moveArm(float timeToMove, int speed){
	setMotor(RightArmMotor, speed);
	setMotor(LeftArmMotor, speed);
	wait(timeToMove, seconds);
	stopAllMotors();
}
void getYellowHub(){
	repeatUntil(getBumperValue(TopButton) == 1)
	{
		setMotor(RightArmMotor,100);
		setMotor(LeftArmMotor,100);
	}
	moveArm(0.7,-100);

}
void placeHubDown(){
	repeatUntil(getBumperValue(BottomButton)== 1)
	{
		setMotor(RightArmMotor,-100);
		setMotor(LeftArmMotor,-100);
	}

	stopAllMotors();

}

void runProgram(){
	moveMotor(MantisLeft,100,degrees,50);
	moveMotor(MantisRight,100,degrees,50);
	turnLeft(-290,degrees,100);
	forward(0.9,seconds,100);
	turnRight(290,degrees,100);
	//moveArm(0.93,100);
	getYellowHub();
	backward(1,seconds,100);
	forward(1,seconds,60);
	moveArm(0.8,100);
	backward(1,seconds,100);
	turnLeft(-290,degrees,100);
	forward(0.95,seconds,100);
//	moveArm(1.48,-100);
	placeHubDown();
	turnLeft(-90,degrees,100);
	backward(0.6, seconds, 100);
	turnRight(90,degrees,100);
	backward(1.14,seconds,100);
	turnRight(290,degrees,100);
	backward(0.7,seconds,100);
	moveMotor(MantisLeft,-100,degrees,50);
	moveMotor(MantisRight,-100,degrees,50);
	moveArm(1.5,100);
	forward(1.5,seconds,100);
	moveArm(3.5,-100);
	repeat(forever){
		stopAllMotors();
	}
}

task main()
{
	wait(300, milliseconds);
	runProgram();
}
