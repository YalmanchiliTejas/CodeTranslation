listS = list(map(str, input().split()))
if int(listS[0]+ listS[1]+ listS[2])%4==0:
    print("YES")
else:
    print("NO")