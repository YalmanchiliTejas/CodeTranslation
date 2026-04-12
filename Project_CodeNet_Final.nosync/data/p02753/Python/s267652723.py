# Station and Bus
S = input()
ans = ['No', 'Yes'][int('A' in S) + int('B' in S) - 1]
print(ans)
