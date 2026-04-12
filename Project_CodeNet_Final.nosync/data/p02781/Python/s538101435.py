N = int(input())
K = int(input())
l = len(str(N))
ans = 0

def neq(n):
    r = 0
    for i in range(10**(len(str(n))-1),n+1):
        ml = 1
        for j in range(len(str(n))):
            ml *= int(str(i)[j])
        if ml != 0:
            r += 1
    return(r)

if l == K:
    print(neq(N))

elif K == 3:
    for i in range(l-2):
        for j in range(i+1,l-1):
            for k in range(j+1,l):
                if i == 0:
                    ans += (int(str(N)[0])-1)*9**2
                    if int(str(N)[1:max(j,2)])>0 and j != 1:
                        ans += 9**2
                    else:
                        if int(str(N)[j+1:max(k,j+2)])>0 and k != j+1:
                                ans += int(str(N)[j])*9
                        else:
                            if int(str(N)[j])*int(str(N)[k]) != 0:
                                ans += neq(int(str(N)[j])*10+int(str(N)[k]))
                            
                else:
                    ans += 9**3
    print(ans)

elif K == 2:
    for i in range(l-1):
        for j in range(i+1,l):
            if i == 0:
                ans += (int(str(N)[0])-1)*9
                if int(str(N)[1:max(j,2)])>0 and j != 1:
                        ans += 9
                else:
                    ans += int(str(N)[j])

            else:
                ans  += 9**2
    print(ans)

else:
    for i in range(l):
        if i == 0:
            ans += int(str(N)[0])
        else:
            ans += 9
    print(ans)

