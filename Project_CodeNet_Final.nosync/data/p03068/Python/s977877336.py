n = int(input())
s = input()
k = int(input())

w = s[k - 1]
print("".join(list(map(lambda x: "*" if x != w else x, s))))

