n,x,m = map(int, input().split())
be = x % m
ans = be
memo = [[0,0] for i in range(m)]
am = [be]
memo[be-1] = [1,0]  #len-1
for i in range(n-1):
    be = be**2 % m
    if be == 0:
        break
    elif memo[be-1][0] == 1:
        kazu = memo[be-1][1]
        l = len(am) -  kazu
        syou = (n-i-1) // l
        amari = (n-i-1)%l
        sum = 0
        for k in range(kazu, len(am)):
            sum += am[k]
        ans = ans + syou*sum
        if amari > 0:
            for j in range(kazu,kazu + amari):
                ans += am[j]
        break
    else:
        ans += be
        am.append(be)
        memo[be-1][0] = 1
        memo[be-1][1] = len(am) -1
print(ans)
