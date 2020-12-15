#ifndef DEFINE_h
#define DEFINE_h

#include "Arduino.h"

struct coords //足回り
{
    double x;
    double y;
    double z;
};

struct gpiop
{
    int one;
    int two;
    int three;
    int four;
};

// Platformの種類を設定
#define PLATFORM_MECHANUM (0)
#define PLATFORM_OMNI4WHEEL (1)
#define PLATFORM_OMNI3WHEEL (2)
#define PLATFORM_DUALWHEEL (3)

#define DRIVE_UNIT (PLATFORM_OMNI4WHEEL)

// ManualControlクラス用の定義
#define JOY_DEADBAND (5)
#define JOY_MAXVEL (2.0)//手動操縦の最高速度変更
#define JOY_MAXANGVEL (1.0)

#define SERIAL_LPMSME1 Serial1
#define SERIAL_ROBOCLAW Serial4
#define SERIAL_LEONARDO Serial5
#define SERIAL_LCD Serial6
#define SERIAL_XBEE Serial7

#define PIN_XBEERESET 66

// スイッチやLEDのピン設定
#define PIN_DIP1 25
#define PIN_DIP2 24
#define PIN_DIP3 69
#define PIN_DIP4 70

#define PIN_SW_UP 32
#define PIN_SW_LEFT 33
#define PIN_SW_RIGHT 31
#define PIN_SW_DOWN 30

#define PIN_SW_WHITE 29
#define PIN_SW_YELLOW 28

#define PIN_ENC_A 26
#define PIN_ENC_B 27

#define PIN_LED_1 20
#define PIN_LED_2 36
#define PIN_LED_3 37
#define PIN_LED_4 38
#define PIN_LED_ENC 40

#define PIN_CSB 10

// Lernardo からのコントローラ用データのマスクデータ
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

// LRTB用define
#define PIN_TOF_ANALOG1 18
#define PIN_TOF_ANALOG2 19
#define PIN_TOF_SWITCH1 3
#define PIN_TOF_SWITCH2 2
#define R_TOF_GND 1.8
#define R_TOF_PWR 3.9
#define DIST_TOF_MAX 3000//LRTBが読む最大の距離(mm)  おそらく、400くらいでいい
#define DIST_TOF_MIN 50//LRTBがよむ最小の距離(mm)
#define LPF_T_TOF (32.0*INT_TIME)

#define DIST_2SENSORS (0.30)        //センサ1,2の間隔距離　単位はm  ----------------------------超重要　より正確な値を出す方法を考えておく必要あり--------------------------
#define DIST_CENTER2EDGE (0.386818) //ロボットの中心から一辺の中点までの距離　単位はm
#define DIST_CENTER2SENSOR23 (0.15)     //センサ3とその辺の中点までの距離　単位はm

#define LIGHT_KABE_BUTTON 4
#define LEFT_KABE_BUTTON 5


// 制御周期
#define INT_TIME (0.01) //( 0.001 )

// フェーズ管理
//#define STATE1      ( 10 )// スタートからゲルゲ受け渡しまで(0から数えて)
//#define STATE1_1    ( 7 )// ベジエTANGENTモード
//#define STATE1_2    ( 8 )// ベジエCOMMANDモード
//#define STATE1_3    ( 9 )// ベジエCOMMANDモード(フェーズの変更は収束判定ではなくリミットスイッチで)
//#define STATE1_4    ( 10 )// 使うか分からないけど
//#define STATE2      ( 14 )// ゲルゲ受け渡し後からシャガイ取得まで
//#define STATE3      ( 15 )// シャガイ取得後からスローイングゾーン待機まで
//#define STATE4      ( 17 )// 投擲位置まで移動
//#define STATE5      ( 20 )//( 19 )// 2個目のシャガイまで
//#define STATE6      ( 22 )//( 21 )// シャガイ取得後からスローイングゾーン待機まで
//#define STATE7      ( 25 )//( 23 )// 3個目のシャガイまで
//#define STATE8      ( 27 )//( 25 )// シャガイ取得後からスローイングゾーン待機まで

//#define STATE_ALL   ( STATE1 + STATE2 + STATE3 + STATE4 )

#endif
