if __name__ == '__main__':
    n = int(input())
    ryokans = list(map(lambda x: int(x), input().split()))

    answer = 0
    for i in range(n):
        ryokans_before_target = ryokans[:i+1]
        highest_indexes = [i for i, x in enumerate(ryokans_before_target) if x == max(ryokans_before_target)]

        if i in highest_indexes:
            answer += 1
    
    print(answer)