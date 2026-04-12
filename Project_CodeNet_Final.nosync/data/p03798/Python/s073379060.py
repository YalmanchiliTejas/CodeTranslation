
def check(s, ans, i) :
    return s[i-1] ^ ans[i-1] ^ ans[i-2] ^ ans[i]

def solve(first, second, s) :
    n = len(s)
    ans = [0] * (n)
    ans[-2] = first;
    ans[-1] = second;



    for i in range(0, n-2) :
        nsame = 0
        nsame ^= s[i-1]
        nsame ^= ans[i-1]
        ans[i] = ans[i-2] ^ nsame
    if check( s, ans, n-2 ) == 0 and check(s, ans, n-1) == 0 :
        ans.append(1)
#    print(ans)
    return ans

N = int(input())
s = input()

data = [0] * N
for i in range(N) :
    data[i] = 1 if s[i] == 'x' else 0
ok = 0

for i in range(2) :
    if ok == 1 :
        break
    for j in range(2) :
        if ok == 1 :
            break
        ans = solve(i, j, data)
        ok = len(ans) - N
if ok == 0 :
    print("-1")
else :
    for i in range(N) :
        print('W' if ans[i] == 1 else 'S', end = "")
    print()

