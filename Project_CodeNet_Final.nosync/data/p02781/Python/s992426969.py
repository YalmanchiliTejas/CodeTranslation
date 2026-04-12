n = input()
k = int(input())
m = len(n)
if k == 1:
    print(int(n[0])+9*(m-1))
elif k == 2:
    if m<2:ans = 0
    else:
        ans = 81*(m-1)*(m-2)//2+(int(n[0])-1)*(m-1)*9
        for i in range(1,m):
            if int(n[i]) != 0:
                ans += (m-i-1)*9+int(n[i])
                break
    print(ans)
else:
    if m<3:ans = 0
    else:
        ans = (m-1)*(m-2)*(m-3)//6*9**3 + (int(n[0])-1)*(m-1)*(m-2)//2*81
        for i in range(1,m):
            if int(n[i])!=0:
                ans += (m-i-1)*(m-i-2)//2*81+(int(n[i])-1)*(m-i-1)*9
                break
        for j in range(i+1,m):
            if int(n[j]) != 0:
                ans += (m-j-1)*9+int(n[j])
                break
    print(ans)