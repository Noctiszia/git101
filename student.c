#include <stdio.h>
#include <string.h>

// struct คือ ที่เก็บข้อมูล**
typedef double cm;
//ประกาศรูปแบบการเก็บข้อมูลด้วย struct ห้ามลืม ;
typedef struct Student_ {            //อย่าใช้ซ้ำ
    char name[100];
    char id[11];
    double score;
} Student;

void print_student(Student stu) {
    printf("%s (%s): %.2lf\n", stu.name , stu.id, stu.score);
    stu.score = 0;
}

//ใช้ร่วมกับ pass by ref ได้
// ถ้าต้องการการเปลี่ยนแปลงในฟังก์ชันต้องใช้ Pointer
void add_score(Student* stuPtr, double score){
    stuPtr->score += score;
}

int main(){
  //นำ struct ไปใช้งาน โดยประกาศตัวแปร struct
  //มอง struct เหมือนเป็น data type
  Student job, bath_;         //ใช้ typedef แล้วไม่ต้อง struct นำหน้า
  Student pp_ = {"peerapat", "62104aaaa", 110}; 
  Student students[10];
  Student* sp = &job;
  //ไม่ควรประกาศ struct ไว้ใน main เพราะเอาไปใช้กับ function อื่นไม่ได้

  strcpy(students[0].name, "Prayad");  //student[0].name ทำไม่ได้นะ
  strcpy(students[0].id, "5555555years");
  students[0].score = 130;

  for(int i = 0;i < 10;i++){
      print_student(students[i]);
  }

  for(int i = 0;i < 10;i++){
      print_student(*(sp + i));
  }

  // cm l = 25.4;

  strcpy(job.name, "chayangoon");
  strcpy(job.id, "62104aaaxx");
  job.score = 90.877725;

  // printf("%s (%s): %.2lf\n", job.name, job.id, job.score);
  // printf("%s (%s): %.2lf\n", pp_.name, pp_.id, pp_.score);

  print_student(job);
  add_score(&job, 10.27);  // ใช้ add_score(sp, 10.27); ก็ได้
  print_student(job);
  add_score(sp, 10.27);  
  print_student(job);


}