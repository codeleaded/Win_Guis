//#include "C:/Wichtig/System/Static/Library/WindowEngine.h"
#include "/home/codeleaded/System/Static/Library/WindowEngine.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#include "/home/codeleaded/System/Static/Library/Scene.h"


Scene scene;

void Component1_React(void* parent,Button* b,ButtonEvent* be){

}
void Component2_React(void* parent,ProgressBar* b,ProgressBarEvent* be){

}
void Component3_React(void* parent,Scrollbar* b,ScrollbarEvent* be){

}
void Component4_React(void* parent,Slider* b,SliderEvent* be){

}
void Component5_React(void* parent,Textbox* b,TextboxEvent* be){

}
void Component6_React(void* parent,Selection* b,SelectionEvent* be){

}
void Component7_React(void* parent,Rotatable* b,RotatableEvent* be){

}

void Setup(AlxWindow* w){
	// Button ProgressBar Scrollbar Slider Textbox Selection Rotatable
	scene = Scene_New();

	Scene_Add(&scene,(Button[]){
		Button_NewStd(
			(void*)&scene,
			"Hello World",
			Component1_React,
			(Vec2){ 32.0f,32.0f },
			Rect_New((Vec2){ 0.0f,0.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Button));
	Scene_Add(&scene,(ProgressBar[]){
		ProgressBar_NewStd(
			(void*)&scene,
			"Hello World",
			Component2_React,
			(Vec2){ 32.0f,32.0f },
			Rect_New((Vec2){ 400.0f,0.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN,
			LIGHT_RED,
			1.0f
		) 
	},sizeof(ProgressBar));
	Scene_Add(&scene,(Scrollbar[]){
		Scrollbar_New(
			(void*)&scene,
			Component3_React,
			Rect_New((Vec2){ 800.0f,0.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Scrollbar));
	Scene_Add(&scene,(Slider[]){
		Slider_New(
			(void*)&scene,
			Component4_React,
			Rect_New((Vec2){ 0.0f,200.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Slider));
	Scene_Add(&scene,(Textbox[]){
		Textbox_NewStd(
			(void*)&scene,
			"Text",
			Component5_React,
			(Vec2){ 32.0f,32.0f },
			Rect_New((Vec2){ 400.0f,200.0f },(Vec2){ 400.0f,100.0f }),
			1U,
			RED,
			GREEN
		) 
	},sizeof(Textbox));
	Scene_Add(&scene,(Selection[]){
		Selection_New(
			(void*)&scene,
			Component6_React,
			Rect_New((Vec2){ 800.0f,200.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Selection));
	Scene_Add(&scene,(Rotatable[]){
		Rotatable_New(
			(void*)&scene,
			Component7_React,
			Rect_New((Vec2){ 0.0f,400.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Rotatable));
}

void Update(AlxWindow* w){
	Scene_Update(&scene,window.Strokes,GetMouse(),GetMouseBefore());

	Clear(BLACK);

	Scene_Render(WINDOW_STD_ARGS,&scene);
}

void Delete(AlxWindow* w){
	Scene_Free(&scene);
}

int main(){
    if(Create("Graphical User Interface",2000,1100,1,1,Setup,Update,Delete))
        Start();
    return 0;
}