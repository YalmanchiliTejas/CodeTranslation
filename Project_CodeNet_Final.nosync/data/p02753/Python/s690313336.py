s = input()

curr_c = s[0]
ans = "No"
for c in s[1:]:
    if(c!=curr_c):
        ans = "Yes"
        break

print(ans)