n = int(input())
s = input()
c = s[int(input()) - 1]

print("".join([ i if i == c else '*' for i in s]))