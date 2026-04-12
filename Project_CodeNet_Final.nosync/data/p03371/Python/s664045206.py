A,B,C,X,Y=list(map(int,input().split()))

ans=0

if 2*C >= A+B:#A,Bを個別に買う
#     print('a')
    ans = A*X+B*Y
else:
    if 2*C <= A and 2*C <= B:
        if X >= Y:
#             print('b_1')
            ans = C*2*X
            
        elif X < Y:
#             print('b_2')
            ans = C*2*Y
            
    elif 2*C <= A:
#         print('b')
        ans = C*2*X + max(0,Y-X)*B
    elif 2*C <= B:
#         print('c')
        ans = max(0,X-Y)*A + C*2*Y
    else:
        if X <= Y:
#             print('d_1')
            ans = C*2*X + max(0,Y-X)*B
            
        elif X > Y:
#             print('d_2')
            ans = max(0,X-Y)*A + C*2*Y
print(ans)