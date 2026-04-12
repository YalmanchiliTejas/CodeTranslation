n = int(input())
s = str(input())

Pattern = [['S', 'S'], ['S', 'W'], ['W', 'S'], ['W', 'W']]

def seigou(n, s, S):
    if s[0] == 'o':
        if S[0] == S[1]:
            if S[-1] == 'S':
                return True
            else:
                return False
        else:
            if S[-1] =='W':
                return True
            else:
                return False
    elif s[0] == 'x':
        if S[0] == S[1]:
            if S[-1] == 'W':
                return True
            else:
                return False
        else:
            if S[-1] =='S':
                return True
            else:
                return False

def seigou_minus(n, s, S):
    if s[-1] == 'o':
        if S[-1] == S[0]:
            if S[-2] == 'S':
                return True
            else:
                return False
        else:
            if S[-2] =='W':
                return True
            else:
                return False
    elif s[-1] == 'x':
        if S[-1] == S[0]:
            if S[-2] == 'W':
                return True
            else:
                return False
        else:
            if S[-2] =='S':
                return True
            else:
                return False



def check(n, s, S):
    for i in range(1, n-1):
        if s[i] == 'o':
            if S[i] == 'S':
                S.append(S[i-1])
            elif S[i] == 'W':
                if S[i-1] == 'W':
                    x = 'S'
                else:
                    x = 'W'
                S.append(x)
        elif s[i] == 'x':
            if S[i] == 'S':
                if S[i-1] == 'W':
                    x = 'S'
                else:
                    x = 'W'
                S.append(x)
            elif S[i] == 'W':
                S.append(S[i-1])
    # S[n-1], S[0]で整合が取れるかどうかを確認
    return S


ans = -1
for pattern in Pattern:
    check_pattern = check(n,s,pattern)
    if seigou(n,s,check_pattern) == True and seigou_minus(n,s,check_pattern) == True:
        ans = check_pattern
    else:
        pass

if ans != -1:
    ans = ''.join(ans)

print(ans)