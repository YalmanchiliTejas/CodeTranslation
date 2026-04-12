N, K = list(map(int, input().split(' ')))
ll = []
for i in range(N):
    l = [c != '.' for c in input()]
    if (any(l)):
        ll.append(l)
tll = [list(x) for x in zip(*ll)]
tans = []
for i in range(len(tll)):
    if (any(tll[i])):
        tans.append(tll[i])
        
ans = [list(x) for x in zip(*tans)]
for i in range(len(ans)):
    print(''.join(['#' if c else '.' for c in ans[i]]))
