N = int(input())
A = [int(input()) for i in range(N)]

A.sort(reverse=True)

def p1(l):
    if N%2 == 1:
        ans = 0
        ans += sum(l[:(N-3)//2])*2
        ans += sum(l[(N-3)//2:(N-3)//2+2])
        ans += sum(l[(N-3)//2+2:])*(-2)
        return ans
    else:
        ans = 0
        ans += sum(l[:(N-2)//2])*2
        ans += sum(l[(N-2)//2:(N-2)//2+1])
        ans += sum(l[(N-2)//2+1:(N-2)//2+2])*(-1)
        ans += sum(l[(N-2)//2+2:])*(-2)
        return ans

def p2(l):
    if N%2 == 1:
        ans = 0
        ans += sum(l[:(N-1)//2])*2
        ans += sum(l[(N-1)//2:(N-1)//2+2])*(-1)
        ans += sum(l[(N-1)//2+2:])*(-2)
        return ans
    else:
        ans = 0
        ans += sum(l[:(N-2)//2])*2
        ans += sum(l[(N-2)//2:(N-2)//2+1])
        ans += sum(l[(N-2)//2+1:(N-2)//2+2])*(-1)
        ans += sum(l[(N-2)//2+2:])*(-2)
        return ans
print(max(p1(A),p2(A)))
    
