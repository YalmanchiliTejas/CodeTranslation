import sys

def ep(*params):
    print(*params,file=sys.stderr)

#() = list(map(int,input().split()))
S = input().rstrip()
if S == 'AAA' or S == 'BBB':
    print("No")
else:
    print("Yes")
    