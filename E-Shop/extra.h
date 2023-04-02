#pragma once

class Error : public exception
{

	string _message;
	string _time;
	int _line;

public:

	Error(const string message, const string time, const int line)
	{
		this->_time = time;
		this->_line = line;
		_message = "\nMessage: " + (string)message
			+ "\nTime: " + _time
			+ "\nLine: " + to_string(_line);
	}

	char const* what() const
	{
		return _message.c_str();
	}
};