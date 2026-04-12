n = input()
k = int(input())
ans = 0
for i in range(1,len(n)):
    if (i < k):
        continue
    else:
        if (k==1):
            ans += 9
        elif (k==2):
            ans += 9*(i-1)*9
        else:
            ans += 9*9*9*(i-1)*(i-2)//2
    #print(ans)
if (k==1):
    ans += int(n[0])
elif (k==2):
    ans += (int(n[0])-1)*(len(n)-1)*9
    #print(ans)
    for i in range(1,len(n)):
        if (int(n[i])>0):
            ans += 9*(len(n)-i-1)
            ans += int(n[i])
            break
        if (i==len(n)-1):
            print(ans)
            exit()
else:
    ans += (int(n[0])-1)*9*9*(len(n)-1)*(len(n)-2)//2
    for i in range(1,len(n)):
        if (int(n[i])>0):
            ans += (int(n[i])-1)*9*(len(n)-i-1)
            ans += 9*9*(len(n)-i-1)*(len(n)-i-2)//2
            t = i
            break
        if (i==len(n)-2):
            print(ans)
            exit()
    for j in range(t+1,len(n)):
        if (int(n[j])>0):
            ans += int(n[j])
            ans += 9*(len(n)-j-1)
            break
print(ans)