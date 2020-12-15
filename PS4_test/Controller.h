#ifndef CONTROLLER_H
#define CONTROLLER_H

#ifndef Arduino_h
#include <Arduino.h>
#include "define.h"
#endif

#define BAUD_RATE_PROMICRO 115200

#define BUTTON_SIKAKU 1
#define BUTTON_SANKAKU 2
#define BUTTON_BATU 3
#define BUTTON_MARU 4

#define BUTTON_L1 5
#define BUTTON_R1 6
#define BUTTON_L2 7
#define BUTTON_R2 8

#define BUTTON_PAD 9
#define BUTTON_PS 10
#define BUTTON_SHARE 11
#define BUTTON_OPTION 12

#define BUTTON_UP 13
#define BUTTON_RIGHT 14
#define BUTTON_DOWN 15
#define BUTTON_LEFT 16

class Controller
{
public:
    Controller(HardwareSerial *_Ser);

    void update();

    /**
     * コントローラのボタン入力状態を返す．
     * 
     * @param buttonNum ボタン番号 1~12
     * @return 1:押されている 0:離されている 2:押された -1:離された
     * 
     */
    int8_t readButton(int buttonNum) const;

    unsigned int getButtonState() const;

    /**
     * ジョイスティックの値を読む
     * @return -1.0 ~ 1.0
     * 
     *      X
     *      ^
     *      |
     * Y<---+----
     *      |
     *      |
     */
    double readJoyLX() const;
    double readJoyLY() const;
    double readJoyRX() const;
    double readJoyRY() const;

    unsigned int readJoyLXbyte() const;
    unsigned int readJoyLYbyte() const;
    unsigned int readJoyRXbyte() const;
    unsigned int readJoyRYbyte() const;

    //coords getVel_xyz(void);
    //coords_4 getMDcmd_fourOmni(double, double, double);

    bool getButtonChanged() const;

    void begin();


private:
    HardwareSerial *Ser;

    unsigned int ButtonState, preButtonState;
    unsigned int LJoyX, LJoyY, RJoyX, RJoyY;

    bool buttonChanged;
    

private:
    int recv_num;

    char recv_msgs[9];
};

#endif