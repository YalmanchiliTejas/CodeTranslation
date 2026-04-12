n = int(input())
a = n % 15
my_result = n * 800 - (n - a) * 200 / 15
print(int(my_result))