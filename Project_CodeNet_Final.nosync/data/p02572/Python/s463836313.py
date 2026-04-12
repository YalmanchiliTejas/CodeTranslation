def resolve():
    numbers = int(input())
    number_list = list(map(int, input().split()))
    answer = 0
    num2 = sum(number_list)
    for num1 in number_list:
        num2 = num2 - num1
        answer += num1*num2
    print(answer%1000000007)
resolve()