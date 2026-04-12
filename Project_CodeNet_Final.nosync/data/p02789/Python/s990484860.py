a,b = [list(map(int, s.split())) for s in open(0)][0]
ans = 'Yes' if a == b else 'No'
print(ans)