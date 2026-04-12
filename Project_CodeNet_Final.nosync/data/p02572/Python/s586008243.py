from sys import stdin
import itertools
def main():
    number = int(input())
    num_list = list(map(int, stdin.readline().split()))
    num_list_sum = sum(num_list)
    total = 0
    for i in range(number):
        num_list_sum -= num_list[i]
        total += num_list[i] * num_list_sum
    print(total % (10**9+7))
if __name__ == '__main__':
    main()