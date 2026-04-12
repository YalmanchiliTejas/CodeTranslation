A,B,C,X,Y = map(int,input().split())

# a,b,c=0,0,0
# min_nedan=5000*(X+Y)
# tmp_nedan=0
# for a in range(X+1):
#     for b in range(Y+1):
#         c = 2*max(X-a,Y-b)
#         tmp_nedan = a*A+b*B+c*C
#         if tmp_nedan < min_nedan:
#             min_nedan = tmp_nedan
#
# print(min_nedan)

min_nedan=5000*(X+Y)
tmp_nedan=0
if A+B > 2*C:
    tmp_nedan += 2*C*min(X,Y)
    if X > Y:
        if A > 2*C:
            tmp_nedan+=2*C*(X-Y)
        elif A <= 2*C:
            tmp_nedan+=A*(X-Y)
    elif X<= Y:
        if B > 2*C:
            tmp_nedan+=2*C*(Y-X)
        elif B <= 2*C:
            tmp_nedan+=B*(Y-X)
elif A+B <= 2*C:
    tmp_nedan += A*X+B*Y

print(tmp_nedan)
