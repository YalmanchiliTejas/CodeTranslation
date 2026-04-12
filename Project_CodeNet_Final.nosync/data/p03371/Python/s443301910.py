def solve():
    A_yen, B_yen, AB_yen, A_mai, B_mai = list(map(int, input().split()))
    AB_average = (A_yen + B_yen)/2
    if (AB_average > AB_yen):
        if(2*AB_yen >= A_yen and 2*AB_yen >= B_yen):
            kakaku = AB_yen*2*min(A_mai, B_mai)
            if(A_mai > B_mai):
                kakaku += A_yen * (A_mai - min(A_mai, B_mai))
            else:
                kakaku += B_yen * (B_mai - min(A_mai, B_mai))
            print(kakaku)
        elif(2*AB_yen < A_yen and 2*AB_yen >= B_yen):
            kakaku = AB_yen*2*min(A_mai, B_mai)
            if(A_mai > B_mai):
                kakaku += 2*AB_yen * (A_mai - min(A_mai, B_mai))
            else:
                kakaku += B_yen * (B_mai - min(A_mai, B_mai))
            print(kakaku)
        elif(2*AB_yen >= A_yen and 2*AB_yen < B_yen):
            kakaku = AB_yen*2*min(A_mai, B_mai)
            if(A_mai > B_mai):
                kakaku += A_yen * (A_mai - min(A_mai, B_mai))
            else:
                kakaku += 2*AB_yen * (B_mai - min(A_mai, B_mai))
            print(kakaku)
        elif(2*AB_yen < A_yen and 2*AB_yen < B_yen):
            kakaku = AB_yen*2*min(A_mai, B_mai)
            if(A_mai > B_mai):
                kakaku += 2*AB_yen * (A_mai - min(A_mai, B_mai))
            else:
                kakaku += 2*AB_yen * (B_mai - min(A_mai, B_mai))
            print(kakaku)
    else:
        kakaku = A_yen * A_mai + B_yen * B_mai
        print(kakaku)


if __name__ == "__main__":
    solve()
