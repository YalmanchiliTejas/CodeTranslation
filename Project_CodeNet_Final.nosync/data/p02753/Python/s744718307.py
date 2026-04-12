S = list(input())
s_A = [s for s in S if 'A' in s]
s_B = [s for s in S if 'B' in s]

if len(s_A) == 3 or len(s_B) == 3:
    ans = 'No'
else:
    ans = 'Yes'

print(ans)
