package main

import "fmt"
import "os"


func main() {

    if len(os.Args) != 2 {
        fmt.Println("Invalid number of parameters")
        os.Exit(2)
    }

    file, err := os.Open(os.Args[1])

    if err != nil {
        fmt.Println("Can't open file: ", os.Args[1])
        os.Exit(2)
    }
    defer file.Close()

    stat, err := file.Stat()

    if err != nil {
        os.Exit(2)
    }

    if stat.IsDir() {
        fmt.Println(os.Args[0], ": ", os.Args[1], "it is directory")
    }

    line_count := 0

    const  MAX_LENGTH = 256
    buff := make ([]byte, MAX_LENGTH)

    for bit_num, _ := file.Read(buff);  bit_num > 0; bit_num, _ = file.Read(buff) {
        for it_arr := 0; it_arr < bit_num; it_arr++ {
            if buff[it_arr] == '\n' {
                line_count++
            }
        }
    }

    fmt.Println(line_count, " ", os.Args[1])


}


