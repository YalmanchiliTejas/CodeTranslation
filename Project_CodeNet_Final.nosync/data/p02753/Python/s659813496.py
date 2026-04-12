s = input()

num = len(set(s))  # set型に変換するとダブりが消えるので、lenで種類数がわかる

if num == 1:
    print("No")
else:
    print("Yes")