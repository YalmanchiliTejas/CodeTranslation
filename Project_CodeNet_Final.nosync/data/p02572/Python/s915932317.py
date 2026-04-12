n = int(input())
a = list(map(int, input().split()))

big = pow(10,9) + 7
sums = pow(sum(a),2)
a_2 = list(map(lambda x: x ** 2, a))

print(((sums-sum(a_2)) // 2)%big)