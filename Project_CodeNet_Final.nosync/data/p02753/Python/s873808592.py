s = input()

ans = 'No'

s = list(set(s))

if len(s) != 1:
    ans = 'Yes'

print(ans) 
