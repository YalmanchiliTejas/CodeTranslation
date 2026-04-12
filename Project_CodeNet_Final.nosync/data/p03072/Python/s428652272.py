def main(input_list):
    count = 0
    for i_1, _ in enumerate(input_list):
        watch_sea = True
        for i_2 in range(i_1):
            if input_list[i_1] < input_list[i_2]:
                watch_sea = False
        if watch_sea:
            count += 1

    return count


if __name__ == "__main__":
    input()
    input_list = list(map(int, input().split()))
    print(main(input_list))
