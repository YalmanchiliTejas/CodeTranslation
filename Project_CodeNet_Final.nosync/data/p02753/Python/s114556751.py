S = list(input())
now = S[0]
ans = False
for i in range(1,len(S),1):
    if S[i] != now :
        ans = True
if ans :
    print("Yes")
else:
    print("No")