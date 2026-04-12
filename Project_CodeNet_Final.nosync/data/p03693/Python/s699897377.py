list_ = input()
list_ = list_.split(" ")
num = list_[0] + list_[1] + list_[2]
num = int(num)

if num % 4 == 0:
    print("YES")
else:
    print("NO")