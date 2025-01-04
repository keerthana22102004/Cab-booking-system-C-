#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX_CITY_LEN 100
#define RADIUS 6371.0 
#define MAX_USERS 100

char* signup_user() {
    char buffer[100];
    printf("ENTER USERNAME:\n ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    char* str = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(str, buffer);
    return str;
}

#define MAX_USERS 100

typedef struct {
    char username[100];
    char password[100];
} User;

User users[MAX_USERS];
int userCount = 0;

void signup_password() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    char username[100];
    char password[100];
    printf("SIGNUP\n");
    printf("ENTER USERNAME:");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("ENTER PASSWORD:");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);

    userCount++;
}

int login() {
    char username[100];
    char password[100];
    printf("LOGIN\n");
    printf("ENTER USERNAME:");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("ENTER PASSWORD:");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; 
        }
    }
    return 0; 
}
typedef struct {
    char name[MAX_CITY_LEN];
    float latitude;
    float longitude;
} PLACE_PICK;

typedef struct {
    char name[MAX_CITY_LEN];
    float latitude;
    float longitude;
} PLACE_DROP;

PLACE_PICK places[] = {
    {"Annanagar", 13.0850, 80.2101},
    {"Nungambakkam", 13.0569, 80.2425},
    {"Mogappair", 13.0837, 80.1750},
    {"Ambattur", 13.1143, 80.1548},
    {"Adyar", 13.0012, 80.2565},
    {"Velacherry", 12.9815, 80.2180},
    {"Perungalathur", 12.8922, 80.0847},
    {"Kalavakkam", 12.7833, 80.2042},
    {"Tnagar",13.0405,80.2337 },
    {"OMR",12.9122 ,80.2279 },
    {"Marina beach",13.0500 ,80.2824},
    {"Puraisaiwakkam",13.0803 ,80.2497 },
    {"Surapet",13.1356 ,80.1718 },
    {"Thambaram",12.9242,80.1275 },
    {"Chrompet",12.9465 ,80.1408 },
    {"Valluvar kottam",13.0527 ,80.2411 },
    {"Koyembedu",13.0729 ,80.1943 },
    {"West mambalam",13.0360 ,80.2247 },
    {"Mylapore",13.0329 ,80.2700 },
    {"Central",13.0827 ,80.2750 },
    {"Egmore",13.0724 ,80.2598 },
    {"Vadapalani",13.0507 ,80.2125 },
    {"Chennai Airport",12.9815 ,80.1636 },
    {"Semozhi poonga",13.0515 , 80.2549},
    {"Thiruvaanmaiyur",12.9877 ,80.2607 },
    {"Mount road",13.0606 ,80.2637 },
    {"Broad way",13.0949,80.2836 },
    {"Sowcarpet",13.0964 ,80.2815 },
};

typedef struct{
    char driver_name[50];
    float latitudes;
    float longitudes;
    float ratings;
}drivers;
 drivers near[]={
     {"Arun", 13.0850, 80.2101,4.8},
    {"Naveen", 13.0569, 80.2425,4.62},
    {"Murugan", 13.0837, 80.1750,4.88},
    {"Arvind", 13.1143, 80.1548,4.56},
    {"Ganesha", 13.0012, 80.2565,5.00},
    {"Vinoth", 12.9815, 80.2180,4.5},
    {"Praveen", 12.8922, 80.0847,5.0},
    {"Krishna", 12.7833, 80.2042,4.2},
    {"Tino",13.0405,80.2337 ,4.79},
    {"Origo",12.9122 ,80.2279 ,4.89},
    {"Mithun",13.0500 ,80.2824,4.66},
    {"Punith",13.0803 ,80.2497 ,4.52},
    {"Suresh",13.1356 ,80.1718 ,4.23},
    {"Thamizh",12.9242,80.1275 ,4.32},
    {"Chandru",12.9465 ,80.1408 ,4.13},
    {"Vallavan",13.0527 ,80.2411 ,4.83},
    {"Keshav",13.0729 ,80.1943 ,5.00},
    {"Widhun",13.0360 ,80.2247 ,5.0},
    {"Myskinn",13.0329 ,80.2700 ,4.32},
    {"Chola",13.0827 ,80.2750 ,4.4},
    {"Enry",13.0724 ,80.2598 ,4.5},
    {"Videsh",13.0507 ,80.2125 ,4.6},
    {"Chiran",12.9815 ,80.1636 ,4.36},
    {"Sethu",13.0515 , 80.2549,4.15},
    {"Thiru",12.9877 ,80.2607 ,4.13},
    {"Monty",13.0606 ,80.2637 ,4.23},
    {"Biskin",13.0949,80.2836 ,4.98},
    {"Sowrav",13.0964 ,80.2815 ,5.00},
 };
#define MINI 1
#define SEDAN 2
#define SUV 3

double calculateCabCost(int cabType, double value) {
    double baseFare;
    double perKilometerRate;

    switch (cabType) {
        case MINI:
            baseFare = 50.0;
            perKilometerRate = 10.0;
            break;
        case SEDAN:
            baseFare = 100.0;
            perKilometerRate = 15.0;
            break;
        case SUV:
            baseFare = 150.0;
            perKilometerRate = 20.0;
            break;
        default:
            return -1.0;
    }

    double totalCost = baseFare + (perKilometerRate * value);
    return totalCost;
}

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(toRadians(lat1)) * cos(toRadians(lat2)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = RADIUS * c;
    return distance;
}
bool validateCouponCode(const char* couponCode) {
    const char* validCode = "123";
    if (strcmp(couponCode, validCode) == 0) {
        return true;  
    } else {
        return false; 
    }
}
int otp() {
  int number, l = 1000, u = 9999;
  int lower = l;
  int upper = u;

  srand(time(NULL));

  number = (rand() % (upper - lower + 1)) + lower;

  return number;
}
typedef struct {
    char name[100];
    float rating;
} Driver;



int main() {
    printf("WELCOME TO OUR CAB BOOKING SYSTEM!!!\n");
      signup_password();

    int flag = login();

    if (flag == 1) {
        printf("LOGIN SUCCESSFUL.\n\n");
    } else {
        printf("INCORECT USERNAME AND PASSWORD.\n");
        printf("LOGIN UNSUCCESSFUL!!\n\n");
        return 0;
    }
    printf("**********\n");
    int j;
    float pick_lat, pick_long;
    int found = 0;
    char city[MAX_CITY_LEN];

    printf("ENTER PICKUP CITY NAME: ");
    fgets(city, MAX_CITY_LEN, stdin);
    city[strlen(city) - 1] = '\0';

    int citySize = sizeof(places) / sizeof(places[0]);

    for (j = 0; j < citySize; j++) {
        if (strcmp(city, places[j].name) == 0) {
            found = 1;
            pick_lat = places[j].latitude;
            pick_long = places[j].longitude;
            break;
        }
    }

    if (!found) {
        printf("CITY NOT FOUND\n");
        return 0;
    }

    PLACE_DROP places1[] = {
        {"Annanagar", 13.0850, 80.2101},
    {"Nungambakkam", 13.0569, 80.2425},
    {"Mogappair", 13.0837, 80.1750},
    {"Ambattur", 13.1143, 80.1548},
    {"Adyar", 13.0012, 80.2565},
    {"Velacherry", 12.9815, 80.2180},
    {"Perungalathur", 12.8922, 80.0847},
    {"Kalavakkam", 12.7833, 80.2042},
    {"Tnagar",13.0405,80.2337 },
    {"OMR",12.9122 ,80.2279 },
    {"Marina beach",13.0500 ,80.2824},
    {"Puraisaiwakkam",13.0803 ,80.2497 },
    {"Surapet",13.1356 ,80.1718 },
    {"Thambaram",12.9242,80.1275 },
    {"Chrompet",12.9465 ,80.1408 },
    {"Valluvar kottam",13.0527 ,80.2411 },
    {"Koyembedu",13.0729 ,80.1943 },
    {"West mambalam",13.0360 ,80.2247 },
    {"Mylapore",13.0329 ,80.2700 },
    {"Central",13.0827 ,80.2750 },
    {"Egmore",13.0724 ,80.2598 },
    {"Vadapalani",13.0507 ,80.2125 },
    {"Chennai Airport",12.9815 ,80.1636 },
    {"Semozhi poonga",13.0515 , 80.2549},
    {"Thiruvaanmaiyur",12.9877 ,80.2607 },
    {"Mount road",13.0606 ,80.2637 },
    {"Broad way",13.0949,80.2836 },
    {"Sowcarpet",13.0964 ,80.2815 },
    };

    printf("\n");
    int i;
    int found1 = 0;
    float drop_lat, drop_long;
    char city1[MAX_CITY_LEN];

    printf("ENTER DESTINATION CITY NAME:");
    fgets(city1, MAX_CITY_LEN, stdin);
    city1[strlen(city1) - 1] = '\0';

    int city1Size = sizeof(places1) / sizeof(places1[0]);

    for (i = 0; i < city1Size; i++) {
        if (strcmp(city1, places1[i].name) == 0) {
            found1 = 1;
            drop_lat = places1[i].latitude;
            drop_long = places1[i].longitude;
            break;
        }
    }

    if (!found1) {
        printf("CITY NOT FOUND \n");
        return 0;
    }

    printf("\n");

    double lat1 = pick_lat;
    double lon1 = pick_long;
    double lat2 = drop_lat;
    double lon2 = drop_long;

    double distance = calculateDistance(lat1, lon1, lat2, lon2);
    printf("THE DISTANCE BETWEEN THE TWO LOCATIONS IS %.2f KILOMETERS.\n", distance);
    printf("**********\n");
    
    int cabType;
    printf("PLEASE SELECT THE TYPE OF CAB:\n");
    printf("1. MINI(up to 4 passengers)\n");
    printf("2. SEDAN(up to 6 passengers)\n");
    printf("3. SUV (up to 8 passengers)\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &cabType);

    double cost = calculateCabCost(cabType, distance);

    if (cost == -1.0) {
        printf("INVALID CAB TYPE.\n");
        return 0;
    }
    int peak()
{
    int cost = calculateCabCost(cabType, distance);
    int extra_charges = 0;
    int tot = 0; 
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);
    localTime->tm_hour += 5;
    localTime->tm_min += 30;

    if (localTime->tm_min >= 60) {
        localTime->tm_min -= 60;
        localTime->tm_hour += 1;
    }

    if (localTime->tm_hour >= 24) {
        localTime->tm_hour -= 24;
    }

    printf("CURRENT INDIAN TIME: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    if (localTime->tm_hour > 7 && localTime->tm_hour < 22) {
        printf("AS THIS IS THE PEAK TIME, EXTRA CHARGES WILL BE APPLIED FOR THE RIDE.\n");
        extra_charges = 100;
        
         tot=extra_charges+cost;
        printf("THE COST IS:%d \n",cost);
        printf("THE PEAKTIME CHARGE IN INR:%d\n ",extra_charges);
        printf("\nTHE TOTAL COST(INCLUDING PEAKTIME CHARGE) IS:%d \n",tot);
    } else {
        printf("NO EXTRA CHARGES WILL BE APPLIED AS IT IS NOT THE PEAK TIME.\n");
         extra_charges=0;
        
        tot=extra_charges+cost;
       
         printf("THE TOTAL COST IS:%d ",tot);
    }

    return(tot);
   
}
    
    int  cost1=peak();
    int advancedBooking;
    printf("**********\n");
    printf("\nDO YOU WANT TO MAKE AN ADVANCED BOOKING?\n");
    printf("1.NO ADVANCED BOOKING\n");
    printf("2. 1-DAY ADVANCED BOOKING\n");
    printf("3. 2-DAY ADVANCED BOOKING\n");
    printf("4. 3-DAY ADVANCED BOOKING\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &advancedBooking);

    double advancedBookingCost = cost1;

    switch (advancedBooking) {
        case 2:
            advancedBookingCost +=150.0;
            break;
        case 3:
            advancedBookingCost += 300.0;
            break;
        case 4:
            advancedBookingCost += 400.0;
            break;
        default:
            break;
    }

    printf("\n");
    if (advancedBooking != 1) {
        printf("TOTAL COST FOR THE CAB RIDE WITH ADVANCED BOOKING IN INR: %.2lf\n", advancedBookingCost);
    } else {
        printf("TOTAL COST FOR THE CAB RIDE IN INR: %.2lf\n", cost);
    }
    printf("**********\n");
    char couponCode[20];
    float discount=50.0;
    int option;
    printf("\nPLEASE ENTER 1 IF YOU WANT TO ADD COUPON CODE \nELSE ENTER 2\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        {
        printf("ENTER THE COUPON CODE:");
        scanf("%s", couponCode);

        if (validateCouponCode(couponCode)) 
        {   
            if (advancedBooking != 1) 
        {
            printf("DISCOUNT AMOUNT:50.00\n");
            printf("TOTAL COST FOR THE CAB RIDE AFTER DISCOUNT IN INR: %.2lf\n", advancedBookingCost-discount);
        } 
        else 
        {
            printf("DISCOUNT AMOUNT:50.0\n");
            printf("TOTAL COST FOR THE CAB RIDE AFTER DISCOUNT IN INR: %.2lf\n", cost-discount);
        }
        } 
        else
        {
            printf("INVALID COUPON CODE. NO DISCOUNT AVAILABLE.\n");
            break;
        }
        }
        case 2:
        {
        break;
        }
        
    }
    printf("**********\n");
    int op;
    float cancel_charge = 0.0;
    printf("\nPLEASE ENTER 1 IF YOU WANT TO CONFIRM YOUR RIDE \nELSE ENTER 2 IF YOU WANT TO CANCEL YOUR RIDE (NOTE THAT CANCELLATION FEE WILL BE CHARGED!!)\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("YOUR RIDE HAS BEEN CONFIRMED!!\n");
            break;
        case 2:
            printf("YOUR RIDE HAS BEEN CANCELLED!!\n");
            cancel_charge = cost * 0.07;
            printf("YOUR CANCELLATION FEE IN INR: %.2f\n", cancel_charge);
            break;
        default:
            printf("INVALID CHOICE!!\n");
            return 0;
    }
    if(op==1)
    {
    printf("\n");
    Driver drivers[100];
    int count = 0;
    float maxRating = 0.0;
    int noofdrivers=sizeof(near)/sizeof(near[0]);
    for(int k=0;k<noofdrivers;k++)
    {
        if(near[k].latitudes==pick_lat && near[k].longitudes==pick_long)
        {
            
           
           printf("%s IS THE DRIVER NEAR YOU,\n", near[k].driver_name);
           printf("WITH THE RATING %2.lf\n",near[k].ratings);
        }
    }
    printf("**********\n");
    
    if(op==1)
    {
    int otpNumber = otp();
    float rating;
    printf("**********\n");
    printf("%d IS THE GENERATED OTP\n",otpNumber);
    printf("PLEASE SHARE THE OTP TO WITH THE DRIVER\n");
    printf("**********\n");
    printf("PLEASE PAY THE GENERATED AMOUNT TO THE DRIVER ONCE THE RIDE IS OVER.\n");
    printf("THANK YOU FOR CHOOSING US!!!\n");
    printf("ENJOY YOUR RIDE!!!\n");
    printf("**********\n");
    printf("ENTER RATING OF THE DRIVER[1-5]:");
    scanf("%f",&rating);
    for(int k=0;k<noofdrivers;k++)
    {
        if(near[k].latitudes==pick_lat && near[k].longitudes==pick_long)
        {
            near[k].ratings=rating;
        }
    }
    printf("YOUR RESPONSE HAS BEEN NOTED,THANK YOU!!!\n");
    }
    printf("**********\n");
 
return(0);
}
}