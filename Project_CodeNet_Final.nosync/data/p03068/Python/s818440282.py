n = int(input())
s = input()
k = int(input())

c = s[k - 1]
ans_list = ["*" if i != c else i for i in s]
ans = ""
ans = ans.join(ans_list)
print(ans)