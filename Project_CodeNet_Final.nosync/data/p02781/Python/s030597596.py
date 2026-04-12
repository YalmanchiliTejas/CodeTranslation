N = input()
K = int(input())
l = len(N)
if K == 1:
    a = int(N[0])
    ans1 = 9*(l-1)+a
if K == 2:
    a=int(N[0])
    ans2 =(a-1)*9*(l-1)
    state = 0
    for n in N[1:]:
        if state:
            ans2 += 9
            continue
        if int(n) != 0:
            state = 1
        n = int(n)
        ans2 += n
    for i in range(2,l):
        ans2 += 81*(i-1)
    if l < K:
        ans2 = 0
if K == 3:
    a = int(N[0])
    ans3 = (a-1)*81*(l-1)*(l-2)/2
    state = 0
    for i in range(1,l):
        n = int(N[i])
        if state:
            ans3 += 81*(l-i-1)
            continue
        if n !=0:
            state = 1
        else:
            continue
        S = 0
        for j in range(i+1,l):
            m = int(N[j])
            if S:
                ans3 += n*9
                continue
            if m != 0:
                S = 1
            ans3 += (n-1)*9+m
    for i in range(3,l):
        ans3 += 729*(i-1)*(i-2)/2
    if l < K:
        ans3 = 0
if K == 1:
    print(ans1)
if K == 2:
    print(int(ans2))
if K == 3:
    print(int(ans3))