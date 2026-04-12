n = int(input())
k = int(input())

def d_sum(digit, k):
    if k==1:
        return 9*digit
    elif k==2:
        return 9**2*digit*(digit-1)//2
    else:
        return 9**3*digit*(digit-1)*(digit-2)//6

s = str(n)
ans = 0

for ind, i in enumerate(s):
    if int(i)==0:
        continue
    digit = len(s)-ind-1
    ans += d_sum(digit, k)
    k -= 1
    if k==0:
        ans += int(i)
        break
    ans += (int(i)-1)*d_sum(digit, k)

print(ans)