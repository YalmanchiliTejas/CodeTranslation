def ox_sw(ox,sw,prev):
    if ox =="o":
        if sw == 1:
            ans = prev
        else:
            ans = -1*prev
    elif ox =="x" :
        if sw ==1:
            ans = -1*prev
        else:
            ans = prev
    return ans

n = int(input())
s  = input()
a1 = [1,1]   #1---> sheep -1 ---> WOLF
a2 = [1,-1]
a3 = [-1,1]
a4 = [-1,-1]
f= False

for a in [a1,a2,a3,a4]:
    for i in range(1,n):
        a.append(ox_sw(s[i],a[i],a[i-1]))
    if a[n] == a[0] and a[1] == ox_sw(s[0],a[0],a[-2]):
        f = True
        break

if f:
    ans = []
    for i in range(n):
        if a[i]==1:
            ans.append("S")
        else:
            ans.append("W")
    print("".join(ans))
else:
    print(-1)
