N = int(input())
s = input()

d = {'S':'W','W':'S'}

def make(s1,s2):
    a = [s1,s2]
    for i in range(N):
        s1,s2 = a[-2:]
        if s2 == 'S':
            if s[i] == 'o':
                s0 = s1
            else:
                s0 = d[s1]
        else:
            if s[i] == 'o':
                s0 = d[s1]
            else:
                s0 = s1
        a.append(s0)
    return a

for s1 in ['S','W']:
    for s2 in ['S','W']:
        a = make(s1,s2)
        possible = a[:2]==a[-2:]
        if possible:
            break
    if possible:
        break

if possible:
    print(''.join(a[1:N+1]))
else:
    print(-1)