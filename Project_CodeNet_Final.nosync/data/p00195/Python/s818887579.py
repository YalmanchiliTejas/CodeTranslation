while True:

    input_data = input()

    if input_data == "0 0":
        break

    input_list = [input().split(" ") for _ in range(4)]
    input_list.insert(0, input_data.split(" "))

    input_list = [(int(count1) + int(count2), char) for (count1, count2), char in
                  zip(input_list, ["A", "B", "C", "D", "E"])]

    result = max(input_list)

    print(result[1], result[0])

