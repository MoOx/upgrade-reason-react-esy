let component = ReasonReact.statelessComponent("Test");
[@react.component]
let make = (~prop1, ~prop2=?, ~prop3=1, ~children, ()) => {
  let children = React.Children.toArray(children);
  ReactCompat.useRecordApi({
    ...component,
    render: _ =>
      <div>
        {prop3->Js.String.make->ReasonReact.string}
        {switch (children) {
         | [|child|] => child
         | _ => React.null
         }}
      </div>,
  });
};
