gyo,retu = map(int,input().split())
ans = [0]*gyo
check = [0]*retu
flag1 = "ng"
for i in range(gyo):
    dum = input()
    for j in range(retu):
        if dum[j] == "#":
            flag1 = "ok"
            check[j] = 1
    if flag1 == "ok":
        ans[i] = dum
        flag1 = "ng"

for l in range(gyo-1,-1,-1):
    if ans[l] == 0:
        ans.pop(l)
ans_len = len(ans)
#print(ans_len)
for k in range(retu-1,-1,-1):
    #print(k,check[k])
    #print(ans)
    if check[k] == 0:
        for m in range(ans_len):
            dum3 = list(ans[m])
            dum3.pop(k)
            ans[m] = dum3
            #dum2 = ans[m]
            #dum2 = dum2.pop(k)
            #ans[m] = dum2

for n in ans:
  print("".join(n))