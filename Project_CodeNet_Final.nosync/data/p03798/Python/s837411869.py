N = int(input())
s = input()

def LieDetector(SW):
    SW = [SW[0]]+[0]*N+[SW[1]]
    for i in range(N):
        if s[i]=='o':
            if SW[i-1]=='S':
                if SW[i]=='S':
                    SW[i+1]='S'
                else:
                    SW[i+1]='W'
            else:
                if SW[i]=='S':
                    SW[i+1]='W'
                else:
                    SW[i+1]='S'
        else:
            if SW[i-1]=='S':
                if SW[i]=='S':
                    SW[i+1]='W'
                else:
                    SW[i+1]='S'
            else:
                if SW[i]=='S':
                    SW[i+1]='S'
                else:
                    SW[i+1]='W'
    return SW[0]==SW[N] and SW[N-1]==SW[N+1],SW

SW = [['S','S'],['S','W'],['W','S'],['W','W']]
for x in SW:
    ans = LieDetector(x)
    if ans[0]:
        break
if ans[0]:
    print(''.join(ans[1][:-2]))
else:
    print(-1)